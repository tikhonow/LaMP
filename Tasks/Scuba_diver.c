#include <stdio.h>
#include <stdlib.h>
int main(void)
{   
    FILE *fin  = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    int xj, yj, hj, xs, ys, hs, us;
    fscanf(fin, "%d%d%d%d%d%d%d" , &xj, &yj, &hj, &xs, &ys, &hs, &us);
    if ( (abs(yj - ys)/us + abs(xj - xs)/us + hs/us) > hj) fprintf(fout, "YES");
    else fprintf(fout, "NO");
}