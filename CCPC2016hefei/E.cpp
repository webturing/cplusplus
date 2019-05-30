#include <iostream>
#include <cstring>
#include <cstdio>

#define maxn 20005
#define LL long long
#define mod 100000007

using namespace std;

int n, d[maxn];
char s[maxn];
LL cnt;

bool dfs(int dep) {
    int c = s[dep] - '0', boom = 0;

    if (dep == n - 1) {
        boom = d[dep] + d[dep - 1];
        if (boom == c) return 1;
        else return 0;
    }
    if (dep == 0) boom = d[0];
    else boom = d[dep - 1] + d[dep];

    if (c < boom) return 0;

    d[dep + 1] = c - boom;
    if (d[dep + 1] > 2) return 0;
    if (d[dep + 1] == 1) cnt++;
    return dfs(dep + 1);
}

LL pow_mod(LL a, LL b) {
    LL ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        LL ans = 0;
        scanf("%s", s);
        n = strlen(s);
        for (int i = 0; i <= 2; i++) {
            memset(d, 0, sizeof(d));
            d[0] = i;
            if (d[0] == 1) cnt = 1;
            else cnt = 0;
            if (dfs(0)) ans = (ans + pow_mod(2LL, cnt)) % mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
 