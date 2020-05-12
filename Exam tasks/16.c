#include <stdio.h>
#include <locale.h>
int main()
{
setlocale(LC_ALL, "Rus");
int sum= 0,s = 0, index, i1;
int i,j, a[7][7];
for(i=0; i<7; ++i){
    for (j=0; j<7; ++j){
        a[i][j] = i + (14*j);
                    }
}
for (i=0; i<7; ++i){
    for (j=0; j<7; ++j)
        printf("%d  ",a[i][j]);
        printf ("\n");
}
printf("Новая матрица:\n");
int n = 1;
for (i = 5; i>0; i--){
    for (j = n;j < 6; j++){
        a[i][j] = 99;
    }
    n++;
}
for (i=0; i<7; ++i){
    for (j=0; j<7; ++j)
        printf("%d  ",a[i][j]);
        printf ("\n");
}
}
