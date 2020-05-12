#include <stdio.h>
#include <stdlib.h>

int transfer(int n){
    if (n > 2) transfer(n/2);
    printf("%d", (n%2));
    }
int main()
{
    int number;
    scanf("%d", &number);
    transfer(number);
}
