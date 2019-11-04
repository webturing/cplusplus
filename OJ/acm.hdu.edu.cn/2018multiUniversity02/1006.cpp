#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>

#define L long long
using namespace std;
const int q = 998244353;
int n, m, t, c[3010][3010], f[3010][3010], x[9000010], a[3010], b[3010], p;

int main() {
    int i, j, k, l;
    for (i = 0; i <= 3000; i++) {
        c[i][0] = 1;
        for (j = 1; j <= i; j++)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % q;
    }
    x[0] = 1;
    for (i = 1; i <= 9000000; i++)
        x[i] = (x[i - 1] << 1) % q;
    while (scanf("%d%d", &n, &m) != EOF) {
        scanf("%d%d", &i, &j);
        a[i] = 1;
        for (k = i + 1; k <= n; k++) {
            a[k] = 1;
            for (l = i; l < k; l++)
                a[k] = (a[k] - (L) a[l] * c[k][l]) % q;
        }
        b[j] = 1;
        for (k = j + 1; k <= m; k++) {
            b[k] = 1;
            for (l = j; l < k; l++)
                b[k] = (b[k] - (L) b[l] * c[k][l]) % q;
        }
        for (k = i; k <= n; k++)
            for (l = j; l <= m; l++)
                f[k][l] = (L) c[n][k] * c[m][l] % q * x[(n - k) * (m - l)] % q;
        p = 0;
        for (k = i; k <= n; k++)
            for (l = j; l <= m; l++)
                p = (p + (L) f[k][l] * a[k] % q * b[l]) % q;
        p = (p + q) % q;
        printf("%d\n", p);
    }
    return 0;
}
