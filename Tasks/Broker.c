#include <stdio.h>
int main()
{
    FILE *fin  = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    int N, A, C, t, r, m, ost=0;
    fscanf(fin,"%d%d%d", &N, &A, &C);
        for (int i = 0; i < N; i++)
        {
            fscanf(fin, "%d%d%d", &t, &r, &m);
            if (( m > t*C )&&( A >= r))
            {
                A += m;
                ost += 2*t*C;
            }
            else
            {
                ost += t*C;
            }
        }
    A -= ost;
    fprintf(fout, "%d", A);
    return 0;
}
