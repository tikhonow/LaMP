#include <stdio.h>
#include <stdlib.h>
int sum (int a, int d , int n){
    int s = 0;
    if (n == 0) return 0;
    else s = a+ sum( a+d, d, n-1);
    }

int main()
{
    int a = 1,d = 2, s, s1;
    printf("%d", ((s = sum(a, d, 10)) - (s1 = sum(a, d , 4)) ));
}
