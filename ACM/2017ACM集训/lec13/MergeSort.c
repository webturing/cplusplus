#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define N 10

void merge(int *a, int l, int q, int r)
{

    int i, j, k, n1, n2;
    int *front, *back;
    n1 = q - l + 1;
    n2 = r - q;
    front = (int *) malloc (n1 * sizeof(int));
    back  = (int *) malloc (n2 * sizeof(int));
    for(i = 0; i < n1; i++)
            front[i] = a[l + i];
    for(i = 0; i < n2; i++)
            back[i] = a[q + 1 + i];
    i = 0, j = 0, k = l;
    while(i < n1 && j < n2)
    {
        if(front[i] <= back[j]) a[k++] = front[i++];
        else a[k++] = back[j++];
    }
    while(i < n1) a[k++] = front[i++];
    while(j < n2) a[k++] = back[j++];
    for(i = 0; i < N; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void mergeSort(int *a, int l, int r)
{
    int m;
    if(l < r)
    {
        m = (l + r)/2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main()
{
    int i;
    int a[] = {9,8,7,6,5,4,3,2,1,0};
    mergeSort(a, 0, N-1);
    return 0;
}
