#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int distance(x, y, x1, y1)
{
    int xc1, yc1;
    float d;
    xc1 = abs(x - x1);
    yc1 = abs(y - y1);
    d = sqrt(pow(xc1, 2)+ pow(yc1, 2));
    return d;
}

int main ()
{
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");

    int x1, y1, x2, y2, x, y;
    fscanf(fin, "%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x, &y);

    int yc, xc;
    xc = (x1 + x2) / 2;
    yc = (y1 + y2) / 2;

    int xc1, yc1, dc;
    xc1= abs(xc - x);
    yc1 = abs(yc - y);
    dc = sqrt(pow(xc1, 2) + pow(yc1, 2));

    int  d1, d2, d3, d4;
    d1 = distance(x, y, x1, y1);
    d2 = distance(x, y, x2, y2);
    d3 = distance(x, y, x1, y2);
    d4 = distance(x, y, x2, y1);

    if ( (d1 < dc) || (d2 < dc) || (d3 < dc) || (d4 < dc) )
    {
        fprintf(fout, "CORNER");
    } else
    {
        fprintf(fout, "CENTER");
    }
    return 0;
}
