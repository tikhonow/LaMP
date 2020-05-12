#include <stdlib.h>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

int search_file (char **argv){
    for (int i = 1; argv[i] != NULL; i++)
	{
        if (argv[i][0] != '-')
			return i;
    }
}
int main(int argc, char* argv[])
{
        int index_file = search_file(argv);
        IplImage *src=0, *dst=0, *dst2=0;

        // имя картинки задаётся первым параметром
        const char* filename = argv[index_file];
        // получаем картинку в градациях серого
        src = cvLoadImage(filename, 0);

        printf("[i] image: %s\n", filename);
        assert( src != 0 );

        // покажем изображение
        cvNamedWindow( "original", 1 );
        cvShowImage( "original", src );

        // получим бинарное изображение
        dst2 = cvCreateImage( cvSize(src->width, src->height), IPL_DEPTH_8U, 1);
        cvCanny(src, dst2, 50, 200);

        cvNamedWindow( "bin", 1 );
        cvShowImage( "bin", dst2);

        //cvScale(src, dst);
        cvSub(src, dst2, dst2);
        cvNamedWindow( "sub", 1 );
        cvShowImage( "sub", dst2);


        // ждём нажатия клавиши
        cvWaitKey(0);

        // освобождаем ресурсы
        cvReleaseImage(&src);
        cvReleaseImage(&dst);
        cvReleaseImage(&dst2);
        // удаляем окна
        cvDestroyAllWindows();
        return 0;
}