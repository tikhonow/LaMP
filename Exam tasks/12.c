#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int nod(a,b){
    if (a == b)return a;
    else if (a > b) nod(a - b, b);
        else nod(a, b - a);
}

int main()
{
    setlocale(LC_ALL, "Rus");
    printf("Введите числа A/B :\n");
    int a, b, c;
    scanf("%d%d", &a, &b);

    c = nod(a,b);
    printf("Сокращенная дробь = ");
    printf("%d%c%d",(a/c),'/',(b/c));
}
