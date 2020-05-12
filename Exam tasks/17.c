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
int m =4, n= 3;
for(i = 6; i > 2; i--){
    for (j = n; j < m; j++){
        a[i][j] = 99;
    }
    m ++;
    n --;
}
int k = 1,t = 6;
for(i = 2; i > -1; i--){
    for (j = k; j < t; j++){
        a[i][j] = 99;
    }
    k ++;
    t --;
}
for (i=0; i<7; ++i){
    for (j=0; j<7; ++j)
        printf("%d  ",a[i][j]);
        printf ("\n");
}
}
