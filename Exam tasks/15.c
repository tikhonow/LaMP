#include <stdio.h>
#include <locale.h>
int main()
{
setlocale(LC_ALL, "Rus");
int min,max;
int i,j, a[8][5];
for(i=0; i<8; ++i){
    for (j=0; j<5; ++j){
        a[i][j] = (4*i)-(2*j) -10;
        min = a[0][0];
        max = a[0][0];
        if (a[i][j] > max){
            max = a[i][j];
        }
        if (a[i][j] < min){
            min = a[i][j];
        }
       }
}
for (i=0; i<8; ++i){
    for (j=0; j<5; ++j)
        printf("%d  ",a[i][j]);
        printf ("\n");
}
printf("Максимальный элемент матрицы = ");
printf("%d", max);
printf ("\n");
printf("Минимальный элемент матрицы = ");
printf("%d", min);
}
