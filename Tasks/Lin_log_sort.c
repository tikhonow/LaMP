#include <stdio.h>
#include <stdlib.h>

void qs(int *array, int first, int last)
{
    if (first < last)
    {
        int left = first, right = last, supporting_element = array[(left + right) / 2];
        do
        {
            while (array[left] < supporting_element) left++;
            while (array[right] > supporting_element) right--;
            if (left <= right)
            {
                int tmp = array[left];
                array[left] = array[right];
                array[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        qs(array, first, right);
        qs(array, left, last);
    }
}
int main(){
    FILE *fin = fopen("input.txt","r");
    FILE *fout = fopen("output.txt","w");
int n;
    fscanf(fin,"%d", &n);
int a[n];
for (int i = 0; i < n; i++){
    fscanf (fin,"%d", &a[i]);
}
qs(a,0,n-1);
for (int i = 0; i < n; i++){
    fprintf(fout,"%d%s", a[i], " ");}
}
