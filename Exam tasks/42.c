#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 1;
    for (int i = 1; i < 11; i++){
        printf("%d %d %d \n" , a, a*a, a*a*a);
        a = a +i;
    }
}
