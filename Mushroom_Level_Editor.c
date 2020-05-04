#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    int N, M,number_mushrooms = 0 , mushroom = 0;
    fscanf(fin, "%d%d", &N, &M);
    char a[N+1][M+1];
    char b[M+1];
    //СЃС‡РёС‚С‹РІР°РЅРёРµ РІ РјР°СЃСЃРёРІ
    for (int i = 0; i < N; i++)
    {
        fscanf(fin, "%s", b);
        for (int j = 0; j < M; j++)
        {
            a[i][j] = b[j];
        }
    }
//РїРѕРёСЃРє
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (a[i][j] == '#')
            {
                if ((a[i-1][j] == '*') && (mushroom < 1))
                mushroom = 1;
            }
            else
            {
            if (mushroom == 1)
            number_mushrooms++;
            mushroom = 0;
            }
        }
        if (mushroom == 1)
        number_mushrooms++;
        mushroom = 0;
    }
fprintf(fout, "%d", number_mushrooms);
return 0;}