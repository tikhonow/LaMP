#include <stdio.h>
#include <stdlib.h>
int find_ai (int a,int i){
    if (i == 1) return a;
    else return (find_ai(a,i-1)* 2 +i);
    }
int main(){
int a1 = 0,ai,n, i;
scanf("%d",&a1);
printf ("%d", (find_ai (a1, 3)) * (find_ai (a1, 7)));
}
