#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>

#define L long long
using namespace std;
const int mod = 998244353;
int n, m, l[30], r[30], x[1100000], y[1100000], a[30], p, q, f[1100000][25], g[25], h[25], s[1100000], w;

inline int power(int a, int b) {
    if (!b)
        return 1;
    int c = power(a, b >> 1);
    c = (L) c * c % mod;
    if (b & 1)
        c = (L) c * a % mod;
    return c;
}

inline int js(int i, int x) {
    int j, k, p = 0;
    for (j = 0, k = x; j <= m; j++, k = (L) k * x % mod)
        p = (p + (L) f[i][j] * k % mod * a[j + 1]) % mod;
    return p;
}

inline void add(int i, int r) {
    int j, k;
    h[0] = 1;
    for (j = 1; j <= m + 1; j++) {
        h[j] = h[j - 1];
        for (k = j - 1; k > 0; k--)
            h[k] = (h[k - 1] - (L) h[k] * r) % mod;
        h[0] = -(L) h[0] * r % mod;
        for (k = 0; k <= j; k++)
            g[k] = (g[k] - (L) f[i][j - 1] * h[k] % mod * a[j]) % mod;
    }
}

int main() {
    int i, j, k, u, v;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d%d", &l[i], &r[i]);
    a[1] = 1;
    for (i = 2; i <= n + 1; i++)
        a[i] = -(L) mod / i * a[mod % i] % mod;
    p = 1;
    f[0][1] = -1;
    f[1][1] = 1;
    for (i = 1; i <= n; i++) {
        m = i;
        w -= l[i];
        r[i] -= l[i];
        for (j = 1; j <= p; j++) {
            y[j] = x[j];
            y[j + p] = x[j] + r[i];
        }
        q = 2 * p;
        sort(y + 1, y + q + 1);
        for (j = 1, k = 0; j <= q; j++)
            if (!k || y[j] > y[k])
                y[++k] = y[j];
        q = k;
        for (j = 1; j < p; j++)
            s[j] = ((L) s[j - 1] + js(j, x[j + 1]) - js(j, x[j])) % mod;
        for (j = q, k = u = p; j >= 0; j--) {
            if (j < q && k > 0 && y[j + 1] - r[i] <= x[k])
                k--;
            if (j < q && u > 0 && y[j + 1] <= x[u])
                u--;
            if (k < u)
                g[0] = ((L) s[u - 1] - s[k] + js(k, x[k + 1]) - js(u, x[u])) % mod;
            for (v = 0; v <= i; v++)
                g[v + 1] = (g[v + 1] + (L) f[u][v] * a[v + 1]) % mod;
            add(k, r[i]);
            for (v = 0; v <= i + 1; v++) {
                f[j][v] = (L) g[v] * power(r[i], mod - 2) % mod;
                g[v] = 0;
            }
        }
        p = q;
        for (j = 1; j <= p; j++)
            x[j] = y[j];
    }
    for (i = 0; i < p && w > x[i + 1]; i++);
    for (j = 0, k = 1, u = 0; j <= n + 1; j++, k = (L) k * w % mod)
        u = (u + (L) k * f[i][j]) % mod;
    printf("%d\n", (u + mod) % mod);
    return 0;
}
