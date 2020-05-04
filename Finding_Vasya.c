#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");

int N, M, X, K;
    fscanf(fin, "%d%d%d%d", &N, &M, &X, &K);

int assumption, pod, floor;
int *house = (int *) calloc(N + 1, sizeof(int));
    for (int i = 0; i < K ; i++) {
        fscanf(fin, "%d", &assumption);
        pod = (X-1)/(M*assumption)+1;
        floor = ((X-(pod-1)*M*assumption)-1)/assumption+1;
        if ((pod - 1) <= N) 
        {
            if (floor > house[pod])
                house[pod] = floor;
                            }
    }

int sum =0;
    for (int i = 0; i < N + 1; i++) 
    {
        sum += house[i];
    }

if (sum==0) fprintf(fout,"%s","-1");
else fprintf(fout,"%d",sum);
}