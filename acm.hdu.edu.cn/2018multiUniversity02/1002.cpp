#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>

using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x, e) (int e=fst[x];e;e=nxt[e])
#define esb(x, e, b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define VIZ {printf("digraph G{\n"); for(int i=1;i<=n;i++) for es(i,e) printf("%d->%d;\n",i,vb[e]); puts("}");}
#define VIZ2 {printf("graph G{\n"); for(int i=1;i<=n;i++) for es(i,e) if(vb[e]>=i)printf("%d--%d;\n",i,vb[e]); puts("}");}
#define SZ 666666
int mx[SZ];
ll MOD;
int s;
ll wk[1026][253], fac[SZ], rfac[SZ];
ll po[2333];
const int N = 200;

ll qp(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

void work(int g) {
    ll *w = wk[g];
    po[0] = w[0] = 1;
    w[1] = g;
    for (int i = 1; i <= N; ++i) po[i] = po[i - 1] * g % MOD;
    for (int i = 2; i <= N; ++i) {
        for (int s = 1; s <= i; ++s)
            (w[i] += w[s - 1] * w[i - s] % MOD *
                     po[min(s, i + 1 - s)]) %= MOD;
        w[i] = w[i] * fac[i - 1] % MOD * rfac[i] % MOD;
    }
}

ll g[2333], f[2333], t[2333], tmp[2333];

void gett(int x) {
    for (int i = 0; i < s; ++i)
        g[i] = wk[i][x] * fac[x] % MOD;
    int r = s + 5;
    for (int i = 0; i < r; ++i) t[i] = f[i] = 0;
    f[0] = 1;
    int u = 1;
    for (int j = 0; j < s; ++j) {
        for (int g = u - 1; g >= 0; --g)
            (f[g + 1] += f[g]) %= MOD, (f[g] *= -j) %= MOD;
        ++u;
    }
    for (int i = 0; i < s; ++i) {
        ll cur = 1;
        for (int j = 0; j < s; ++j)
            if (j != i) cur = cur * (i - j) % MOD;
        cur = qp(cur, MOD - 2) * g[i] % MOD;
        //r=f/(x-i)
        tmp[u] = 0;
        for (int j = 0; j < u; ++j) tmp[j] = f[j];
        for (int j = u - 1; j >= 1; --j)
            (tmp[j - 1] += tmp[j] * i) %= MOD;
        for (int j = 0; j < u; ++j)
            (t[j] += tmp[j + 1] * cur) %= MOD;
    }
}

int main() {
    scanf("%lld", &MOD);
    fac[0] = 1;
    for (int i = 1; i < SZ; ++i)
        fac[i] = fac[i - 1] * i % MOD;
    rfac[SZ - 1] = qp(fac[SZ - 1], MOD - 2);
    for (int i = SZ - 1; i >= 1; --i)
        rfac[i - 1] = rfac[i] * i % MOD;
    mx[0] = 0;
    mx[1] = 1;
    for (int i = 2; i <= N; ++i) {
        int g = i / 2;
        for (int s = g - 3; s <= g + 3; ++s)
            if (s >= 1 && s <= i)
                mx[i] = max(mx[i], mx[s - 1] + mx[i - s] + min(s, i + 1 - s));
    }
    s = mx[N] + 3;
    for (int i = 0; i < s; ++i) work(i);
    int n, x;
    while (scanf("%d%d", &n, &x) != EOF) {
        if (x > mx[n]) {
            puts("0");
            continue;
        }
        gett(n);
        int ans = t[x];
        ans = (ans % MOD + MOD) % MOD;
        printf("%d\n", int(ans));
    }
}
