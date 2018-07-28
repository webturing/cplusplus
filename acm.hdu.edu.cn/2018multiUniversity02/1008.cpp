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
map<pair<ll, ll>, ll> rs;
ll x;

ll mul(ll a, ll b) {
    ll ans = 0;
    while (a)
        ans ^= b * (a & -a), a -= a & -a;
    return ans;
}

const int MOD = 998244353;

ll f(ll n, ll g) {
    if (rs.count(make_pair(n, g)))
        return rs[make_pair(n, g)];
    ll &tg = rs[make_pair(n, g)];
    if (!n) return tg = __builtin_popcountll(g);
    ll t = (n & 1) ? mul(g, x) : g, a = 0, b = 0;
    for (int i = 0; i <= 30; ++i) {
        if (t & (1LL << i)); else continue;
        if (i & 1) a |= 1LL << (i >> 1);
        else b |= 1LL << (i >> 1);
    }
    return tg = (f(n >> 1, b) + f(n >> 1, a)) % MOD;
}

int n, a[SZ];

int main() {
    while (scanf("%d", &n) != EOF) {
        rs.clear();
        x = 1;
        for (int i = 1; i <= 10; ++i) {
            scanf("%d", a + i);
            if (a[i] & 1) x |= 1LL << i;
        }
        ll ans = f(n, 1);
        ans = (ans % MOD + MOD) % MOD;
        printf("%d\n", ans);
    }
}
