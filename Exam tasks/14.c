#include <stdio.h>
#include <locale.h>
int main()
{
setlocale(LC_ALL, "Rus");
int sum= 0,s = 0, index, i1;
int i,j, a[8][5];
for(i=0; i<8; ++i){
    for (j=0; j<5; ++j){
        a[i][j] = (4*i)-(2*j) -10;
        s = s +  a[i][j];
        index= i;}
  if (s> sum) {
        sum =s;
        i1 = index;
  }
}
for (i=0; i<8; ++i){
    for (j=0; j<5; ++j)
        printf("%d  ",a[i][j]);
        printf ("\n");
}
printf ("Строка № ");
printf ("%d  ",index);
printf("с максимальной суммой элементов\n");
for (i= index; i<index+1; i++){
    for (j=0; j<5; ++j){
        printf("%d  ",a[i][j]);
}

}}
