#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

long long tot;

void merge(int *a, int l, int q, int r)
{

    int i, j, k;
    int *temp = (int*)malloc((r - l + 1) * sizeof(int));
    i = l, j = q + 1, k = 0;
    while(i <= q && j <= r)
        if(a[i] <= a[j]) temp[k++] = a[i++];
        else {
            temp[k++] = a[j++];
            tot += (q - i + 1);
        }
    while(i <= q) temp[k++] = a[i++];
    while(j <= r) temp[k++] = a[j++];
    for(i = l; i <= r; i++)
        a[i] = temp[i-l];
    free(temp);
}

void mergeSort(int *a, int l, int r)
{
    int m;
    if(l < r)
    {
        m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main()
{
    int t, i, n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        tot = 0;
        int *a = (int*)malloc(n * sizeof(int));
        for(i = 0; i < n; i++)
            scanf("%d",a+i);
        mergeSort(a, 0, n-1);
        printf("%lld\n", tot);
        free(a);
    }
    return 0;
}
