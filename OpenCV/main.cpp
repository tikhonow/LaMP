/* взять open cv скомпилировать из исходников и написать tools который
5-10 баллов - редактирование и обработка( фильтр, поворот, при помощи мышки, мета информация) изображений
10-20 баллов - на изображении ищет треугольники или квадраты с помощью open cv
До 21 января	
g++ main.cpp -o tools `pkg-config --cflags --libs opencv` 
-f   фильтр                                 
-r   поворот на укахзанный пользователем угол
-i   мета-данные                           
-o   не выводи original image  */

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <stdlib.h>
#include <stdio.h>

//Функция поиска индекса файла
int search_index_file (char **argv){
    for (int i = 1; argv[i] != NULL; i++)
	{
        if (argv[i][0] != '-')
			return i;
    }
    return 0;
}
//поиск опций
int search_option(char **argv, int index_file, const char* param){
    for (int i = 1; i < index_file; ++i) 
    {
        if (strcmp(argv[i], param) == 0) 
            return 1;

    }
    return 0;
}


// функция поворота изобg++ main.cpp -o tools `pkg-config --cflags --libs opencv` ражения на заданный угол
IplImage *rotate(IplImage* _image, double _angle)
{
    CvMat* rot_mat = cvCreateMat(2, 3, CV_32FC1);
    CvPoint2D32f center = cvPoint2D32f(_image->width/2, _image->height/2);
    double angle = _angle;
    double scale = 1.0;
    cv2DRotationMatrix(center,angle,scale,rot_mat);
        
    IplImage* Temp = 0;
    Temp = cvCreateImage(cvSize(_image->width, _image->height) , _image->depth, _image->nChannels);

    cvWarpAffine(_image,Temp,rot_mat);

    cvCopy(Temp, _image);

    cvReleaseImage(&Temp);
    cvReleaseMat(&rot_mat);
    return _image;
}
IplImage* image = 0;
IplImage* src = 0;
IplImage* dst[1];
int main(int argc, char* argv[])
{
    //получение имени файла
    int file_i = search_index_file(argv);
    const char* filename = argv[file_i];

    //проверка корректности запуска
    if (argc == 1 )
    {
        printf("Введите: ./tools [OPTION]... image_file...\n"
        "[OPTION]:\n"
        "-f накладывает черно-белый\n"                                 
        "-r поворачивает изображение\n"
        "-i выводит мета-данные изображения\n"                           
        "-o не выводит оригинальное изображение\n");
        return 0;
    }
    //проверка файла
    FILE *file = fopen(argv[file_i], "rt");
    if (file == NULL){
        printf("Файл с указанным именем не найден!\n");
        return 0;
    }

    //получение параметров
    int information_option = search_option(argv, file_i, "-i");
    int rotation_option    = search_option(argv, file_i, "-r");
    int filtr_option       = search_option(argv, file_i, "-f");
    int original_option    = search_option(argv, file_i, "-o");
        
    // получаем картинку
    
    // клонируем картинку
    try {
        image = cvLoadImage(filename,1);
        src = cvCloneImage(image);
    } catch (std::out_of_range e) {
        printf("Файл с указанным именем invalid!\n");
        return 0;
    }    

    // создание уменьшенных картинок (разный тип интерполяции)
    int i;
    for(i=0;i<1; i++){
        dst[i] = cvCreateImage( cvSize(image->width/2, image->height/2), image->depth, image->nChannels );
        cvResize(image, dst[i], i);
    }

    printf("[i] image: %s\n", filename);
    assert( src != 0 );
    image = cvCloneImage(dst[0]);

    // окно для отображения картинки
    if (original_option == 0)
    {
        cvNamedWindow("Оригинальное изображение", CV_WINDOW_AUTOSIZE);
        cvShowImage("Оригинальное изображение", dst[0]);
    }

    // выводим в консоль информацию о картинке
    if (information_option != 0)
    {
        printf( "[i] channels:  %d\n",          image->nChannels );
        printf( "[i] pixel depth: %d bits\n",   image->depth );
        printf( "[i] width:       %d pixels\n", image->width );
        printf( "[i] height:      %d pixels\n", image->height );
        printf( "[i] image size:  %d bytes\n",  image->imageSize );
        printf( "[i] width step:  %d bytes\n",  image->widthStep );
    }

    //  вращение и применение черно -белого фильтра
    if(rotation_option || filtr_option)
    {   
        if (rotation_option)
        {
            printf("Введите градус поворота\n");
            double param;
            scanf("%lf", &param);
            image = rotate(image, param);
            cvSaveImage(argv[argc - 1], image,0);
        }
        if (filtr_option)
        {
            if (!rotation_option) image = cvLoadImage(filename, 0);
                else image = cvLoadImage(argv[argc - 1], 0);
        }
        //выбор имени окна , в зависимсоти от выбранных опций 
        char win[10];
        if (filtr_option && !rotation_option) char win[] = "Черно-белое изображение";
        else char win[] = "Повернутое изображение";
        if (filtr_option && rotation_option) char win[] = "Повернутое черно-белое изображение";
        cvSaveImage(argv[argc - 1], image, 0);
        cvNamedWindow( win, 1 );
        cvShowImage( win, image );
    }
        
    // ждём нажатия клавиши
    cvWaitKey(0);

    // освобождаем ресурсы
    cvReleaseImage(& image);
    cvReleaseImage(&src);

    // удаляем все  окна
    cvDestroyAllWindows;
    return 0;
}
// ncurses