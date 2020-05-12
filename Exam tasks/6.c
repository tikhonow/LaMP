// 1 2 6 24 120      вывод 120+2= 122
#include <stdio.h>
#include <stdlib.h>
int find_ai (int a,int i){
    if (i == 0) return a;
    else return (find_ai(a,i-1)* i);
    }
int main(){
int a1,ai,n, i;
scanf("%d",&a1);

//for (i = 1; i< (n +1); i++){
    //ai = find_ai (a1, i);
    printf ("%d", ((find_ai (a1, 2)) + (find_ai (a1, 5))));
   // }
}
