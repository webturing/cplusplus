#include<bits/stdc++.h>

#define L long long
using namespace std;
const int q = 998244353;
int n, m, x[1000010], f[1000010], g[1000010];

int main() {
    int i, j, k, l;
    scanf("%d%d", &n, &m);
    x[1] = 1;
    for (i = 2; i <= n; i++)
        x[i] = q - (L) q / i * x[q % i] % q;
    for (i = 2; i <= n; i++) {
        f[i] = 2ll * x[i] * x[i + 1] % q;
        g[i] = x[i];
    }
    for (i = 2; i <= n; i++) {
        f[i] = (f[i] + f[i - 1]) % q;
        g[i] = (g[i] + g[i - 1]) % q;
    }
    for (i = 2; i <= n; i++) {
        f[i] = (f[i] + f[i - 1]) % q;
        g[i] = (g[i] + f[i - 1]) % q;
    }
    while (m--) {
        scanf("%d%d", &i, &j);
        if (i == 1 && j == n) {
            printf("1\n");
            continue;
        }
        int p = n + j - i;
        p = (p - g[i - 1] - g[n - j]) % q;
        if (i == 1 || j == n)
            p = (p - 2ll * g[j - i + 1]) % q;
        else
            p = (p - 2ll * f[j - i + 1]) % q;
        p = (p + q) % q;
        printf("%d\n", p);
    }
    return 0;
}
