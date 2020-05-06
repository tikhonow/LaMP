#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fin = fopen("input.txt","r");
    FILE *fout = fopen("output.txt","w");
    int N, M, counter= 0;
    fscanf(fin,"%d%d", &N, &M);
    if (M == 0)
    {
        fprintf(fout, "%d", 0);
    }
        else
        if(N == 1)
        {
            fprintf(fout, "%d", 2);
        }
            else
            if(M == 1)
            {
                counter = 2 * N;
                fprintf(fout, "%d",counter);
            }
                else
                if(M > N)
                {
                    counter = N + 1;
                    fprintf(fout,"%d",counter);
                }
                    else
                        {
                            counter = ( ( ( N/M )*M) + ( N / M ) );
                            if((N % M) == 1)
                            {
                                counter += 2;
                                fprintf(fout, "%d", counter);
                            }
                                else 
                                if((N % M) == 0)
                                {
                                    fprintf(fout, "%d", counter);
                                }
                                    else
                                    {
                                        counter += ( (N % M) + 1);
                                        fprintf(fout, "%d", counter);
                                    }
                        }

return 0;
}