#include <stdio.h>

int main()
{
    int m,n,i,j;
    int arr[210][210];
    scanf("%d%d",&m, &n);
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            scanf("%d",&arr[i][j]);
    int first=1;
    for(i = 0; i < (m+1)/2 && i < (n+1)/2; i++)
    {
        for(j = i; j < m-i; j++) {
            if (first) {
                printf("%d",arr[j][i]);
                first = 0;
            }else printf(" %d", arr[j][i]);

        }
        for(j = i+1; j < n-i; j++ )
            printf(" %d",arr[m-i-1][j]);
        if(n-i-1 > i)
        {
            for(j = m-i-2; j >= i; j--)
                printf(" %d",arr[j][n-i-1]);
        }
        if (m-i-1 > i)
        {
            for(j = n-i-2; j > i; j--)
                printf(" %d",arr[i][j]);
        }
    }

    return 0;
}