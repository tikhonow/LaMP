#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    int N;
    int count = 0;
    fscanf( fin,"%d" , &N );
    int balls[N];
    char pp[N];
    for (int i = 0; i < N; i++)
    {
        fscanf(fin, "%d" , &balls[i] );
    }
    for (int i = 0; i < N; i++)
    {
        fscanf(fin,"%s", &pp[i]);
        if (pp[i] == '+')
        {
            count = count + balls[i];
        }
    }
    fprintf(fout,"%d", count);
    return 0;
}