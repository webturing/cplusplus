#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define N 10


void quickSort(int *a, int l, int r)
{
    if(l>=r)return ;
    int k, i = l, j = r, temp = a[i];
    while (i < j)
    {
        while(i < j && a[j] > temp) j--;
        if(i < j) a[i++] = a[j];
        while(i < j && a[i] < temp) i++;
        if(i < j) a[j--] = a[i];
    }
    a[i] = temp;
    quickSort(a, l, i-1);
    quickSort(a, i+1, r);
}

int main()
{
    int k,a[N] = {1,2,3,4,5,6,7,8,9};
    quickSort(a,0,N-1);
    return 0;
}
