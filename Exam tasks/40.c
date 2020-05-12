#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    int a, b, c;
    printf("¬ведите 3 числа : ");
    scanf("%d%d%d", &a, &b, &c);
    printf("%d\n", a+b+c);
    printf("%d\n", a*b*c);
    printf("%.3f\n", ((a+b+c)/3.0) );
}

