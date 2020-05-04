#include <stdio.h>

int main()
{
    FILE* fin=fopen("input.txt","r");
    FILE* fout=fopen("output.txt","w");
    int N;
    fscanf(fin,"%d",&N);
    int a[1000];
    int b[1000];
    int c[1000];

        for (int i=0;i<N;i++)
        {
            fscanf(fin,"%d",&a[i]);
            b[i]=a[i];
            c[i]=a[i];
        }
    int sum1 = 0;
        for (int i=0;i<N;i+=2)
        {
            if (N%2==0)
        {
            if (i==0)
            {
                if (b[i]<=b[i+1])
                {
                    b[i]=b[i+1]+1;
                    sum1=sum1+a[i+1]-a[i]+1;
                }
            }
            else
            {
                if ((b[i]<=b[i+1]) || b[i]<=b[i-1])
                {
                    if (b[i-1]<b[i+1])
                    {
                        b[i]=b[i+1]+1;
                        sum1=sum1+a[i+1]-a[i]+1;
                    }
                    else
                    {
                        b[i]=b[i-1]+1;
                        sum1=sum1+a[i-1]-a[i]+1;
                    }
                }
            }
        }
        else
        {
            if (i==0)
            {
                if (b[i]<=b[i+1])
                {
                    b[i]=b[i+1]+1;
                    sum1=sum1+a[i+1]-a[i]+1;
                }
            }
            else
            {
                if (i==N)
                {
                    if (b[i]<=b[i-1])
                    {
                        b[i]=b[i-1]+1;
                        sum1=sum1+a[i-1]-a[i]+1;
                    }
                }
                else
                {
                    if ((b[i]<=b[i+1]) || b[i]<=b[i-1])
                    {
                        if (b[i-1]<b[i+1])
                        {
                            b[i]=b[i+1]+1;
                            sum1=sum1+a[i+1]-a[i]+1;
                        }
                        else
                        {
                            b[i]=b[i-1]+1;
                            sum1=sum1+a[i-1]-a[i]+1;
                        }
                    }
                }
            }
        }
    }
    int sum2=0;
        for (int i=1;i<N;i+=2)
        {
            if (i==N-1)
            {
                c[i+1]=0;
            }
            if (N%2==0)
            {
            if (i==N)
            {
                if (c[i]<=c[i-1])
                {
                    c[i]=c[i-1]+1;
                    sum2=sum2+a[i-1]-a[i]+1;
                }
            }
            else
            {
                if ((c[i]<=c[i+1]) || c[i]<=c[i-1])
                {
                    if (c[i-1]<c[i+1])
                    {
                        c[i]=c[i+1]+1;
                        sum2=sum2+a[i+1]-a[i]+1;
                    }
                    else
                    {
                        c[i]=c[i-1]+1;
                        sum2=sum2+a[i-1]-a[i]+1;
                    }
                }
            }
        }
        else
        {
            if ((c[i]<=c[i+1]) || c[i]<=c[i-1])
            {
                if (c[i-1]<c[i+1])
                {
                    c[i]=c[i+1]+1;
                    sum2=sum2+a[i+1]-a[i]+1;
                }
                else
                {
                    c[i]=c[i-1]+1;
                    sum2=sum2+a[i-1]-a[i]+1;
                }
            }
        }
    }
    if (sum1<=sum2)
    {
        for(int i=0;i<N;i++)
        {
            fprintf(fout,"%d ",b[i]);
        }
    }
        else
        {
            for(int i=0;i<N;i++)
            {
                fprintf(fout,"%d ",c[i]);
            }
        }
}
