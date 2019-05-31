#include <bits/stdc++.h>

using namespace std;
typedef long double LD;

inline int rd(int x = 0) { return (scanf("%d", &x), x); }

#define P(x) ((x)*(x+1)/2)
const int N = 31;
int n, m, C[N][N], f[N][N][P(N)], g[N][P(N) * 2];

inline void solve() {
    n = rd(), m = rd();
    memset(g, 0, sizeof(g));
    for (int bg = 1; bg <= n; ++bg) {
        memset(f, 0, sizeof(f));
        f[bg][1][0] = 1;
        for (int i = bg; i <= n; ++i)
            for (int k = 1; k <= n; ++k)
                for (int t = 0; t <= P(n); ++t)
                    if (f[i][k][t])
                        for (int j = i + 1; j <= n; j++)
                            f[j][k + 1][t + P(j - i - 1)] += f[i][k][t];
        for (int i = bg; i <= n; i++)
            for (int k = 1; k <= n; k++)
                for (int t = 0; t <= P(n); ++t)
                    if (f[i][k][t])
                        g[k][t + P(bg - 1 + n - i)] += f[i][k][t];
    }
    LD ans = 0, sgn = 1;
    for (int i = n - m + 1; i <= n; i++) {
        for (int j = 0; j < n * n; j++)
            if (g[i][j])
                ans += sgn * C[i - 1][n - m] / (1.0 - (LD) j / n / n) * g[i][j];
        sgn = -sgn;
    }
    printf("%.12f\n", (double) ans);
}

int main() {
    for (int i = 0; i < N; i++) C[i][0] = 1;
    for (int i = 1; i < N; i++)
        for (int j = 1; j < N; j++)
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    for (int T = rd(); T; T--) solve();
}