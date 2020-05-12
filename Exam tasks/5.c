#include <stdio.h>
#include <stdlib.h>
int find_ai (int a, int q, int i){
    if (i == 0) return a;
    else return (find_ai(a, q, i-1)* q);
    }
int main(){
int a1,ai, q, n, i;
scanf("%d%d%d",&a1, &q, &n);
for (i = 0; i< n; i++){
    ai = find_ai (a1,q,i);
    printf ("%d%c", ai,' ');
                    }
}
