#include<bits/stdc++.h>

using namespace std;
int n, m, w[100010], a[100010], b[300010], c[300010], d[300010], r = 1, p;
vector<int> f, x[100010];
bool u[100010];

inline void add_(int i, int j) {
    w[i]++;
    b[++r] = j;
    c[r] = a[i];
    a[i] = r;
}

inline void add(int i, int j) {
    add_(i, j);
    add_(j, i);
}

inline void dfs(int i) {
    int j;
    u[i] = 1;
    if (w[i] & 1)
        f.push_back(i);
    for (j = a[i]; j; j = c[j])
        if (!u[b[j]])
            dfs(b[j]);
}

inline void dfs2(int i) {
    int j;
    for (j = a[i]; j; j = c[j])
        if (!d[j]) {
            d[j] = d[j ^ 1] = 1;
            dfs2(b[j]);
            if (j > 2 * m + 1)
                p++;
            else
                x[p].push_back(j / 2 * (2 * (j & 1) - 1));
        }
}

int main() {
    int i, j, k;
    while (scanf("%d%d", &n, &m) != EOF) {
        for (i = 1; i <= m; i++) {
            scanf("%d%d", &j, &k);
            add(j, k);
        }
        for (i = 1; i <= n; i++)
            if (!u[i] && w[i]) {
                dfs(i);
                if (!f.size()) {
                    f.push_back(i);
                    f.push_back(i);
                }
                for (j = 2; j < f.size(); j += 2)
                    add(f[j], f[j + 1]);
                p++;
                dfs2(f[0]);
                f.clear();
            }
        printf("%d\n", p);
        for (i = 1; i <= p; i++) {
            printf("%d ", x[i].size());
            for (j = 0; j < x[i].size(); j++)
                printf("%d ", x[i][j]);
            printf("\n");
            x[i].clear();
        }
        for (i = 1; i <= n; i++)
            a[i] = w[i] = u[i] = 0;
        for (i = 1; i <= r; i++)
            d[i] = 0;
        p = 0;
        r = 1;
    }
    return 0;
}
