#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <stdlib.h>
#include <stdio.h>

IplImage* image = 0;
IplImage* src = 0;
IplImage* dst[1];
// функция поворота изображения на заданный угол
IplImage *rotate(IplImage* _image, double _angle,double scale1)
{
    CvMat* rot_mat = cvCreateMat(2, 3, CV_32FC1);
    CvPoint2D32f center = cvPoint2D32f(_image->width/2, _image->height/2);
    double angle = _angle;
    double scale = scale1 ;
    cv2DRotationMatrix(center,angle,scale,rot_mat);
        
    IplImage* Temp = 0;
    Temp = cvCreateImage(cvSize(_image->width, _image->height) , _image->depth, _image->nChannels);

    cvWarpAffine(_image,Temp,rot_mat);

    cvCopy(Temp, _image);

    cvReleaseImage(&Temp);
    cvReleaseMat(&rot_mat);
    return _image;
}
// обработчик событий от мышки
void myMouseCallback( int event, int x, int y, int flags, void* param )
{
        IplImage* img = (IplImage*) param;

        switch( event ){
                case CV_EVENT_MOUSEMOVE: 
                        break;

                case CV_EVENT_LBUTTONDOWN:
                        //printf("%d x %d\n", x, y);
                        rotate(img, 10, 1);
                        break;

                case CV_EVENT_LBUTTONUP:
                        break;
        }
}

int main(int argc, char* argv[])
{
        // имя картинки задаётся первым параметром
        const char* filename = argc == 2 ? argv[1] : "Image0.jpg";
        // получаем картинку
        image = cvLoadImage(filename,1);
        // клонируем картинку 
        src = cvCloneImage(image);

        // создание уменьшенных картинок (разный тип интерполяции)
        int i;
        for(i=0;i<1; i++){
                dst[i] = cvCreateImage( cvSize(image->width/2, image->height/2), image->depth, image->nChannels );
        cvResize(image, dst[i], i);}

    printf("[i] image: %s\n", filename);
    assert( src != 0 );
    image = cvCloneImage(dst[0]);

        // окно для отображения картинки
        cvNamedWindow("original",CV_WINDOW_AUTOSIZE);

        // вешаем обработчик мышки
        cvSetMouseCallback( "original", myMouseCallback, (void*) image);

        while(1){
                // показываем картинку
                src = cvCloneImage(image);
                cvShowImage( "original", src );

                char c = cvWaitKey(33);
                if (c == 27) { // если нажата ESC - выходим
                        break;
                }
        }

        // освобождаем ресурсы
        cvReleaseImage(&image);
        cvReleaseImage(&src);
        // удаляем окно
        cvDestroyWindow("original");
        return 0;
}