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
    printf("������� ����� A, B, C :\n");
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    int nodAB, nodAB_C, nodABnodAB_c;
    nodAB        = nod (a,b);
    nodAB_C      = nod (nodAB, c);
    nodABnodAB_c = nod ( nodAB, nodAB_C );

    printf("��� ������ ����� = ");
    printf("%d", nodABnodAB_c);
}
