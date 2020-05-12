#include <stdio.h>
#include <stdlib.h>
int find_ai (int a, int d, int i){
    if (i == 0) return a;
    else return (find_ai(a, d, i-1) +d );
    }
int main(){
int a1,ai, d, n, i;
scanf("%d%d%d",&a1, &d, &n);
for (i = 0; i< n; i++){
    ai = find_ai (a1,d,i);
    printf ("%d%c", ai,' ');
                    }
}
