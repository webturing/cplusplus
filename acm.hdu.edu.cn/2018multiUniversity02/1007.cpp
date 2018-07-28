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
//std�������������������Ӷ�
//�ɳ־û��ֿ�󷨺�
#define BUFSIZE 5000000
namespace fob { char b[BUFSIZE] = {}, *f = b, *g = b + BUFSIZE - 2; }
#define pob (fwrite(fob::b,sizeof(char),fob::f-fob::b,stdout),fob::f=fob::b,0)
#define pc(x) (*(fob::f++)=(x),(fob::f==fob::g)?pob:0)

struct foce {
    ~foce() {
        pob;
        fflush(stdout);
    }
} _foce;
namespace ib { char b[100]; }

inline void pint(int x) {
    if (x == 0) {
        pc(48);
        return;
    }
    //if(x<0) {pc('-'); x=-x;} //����и����ͼ��� 
    char *s = ib::b;
    while (x) *(++s) = x % 10, x /= 10;
    while (s != ib::b) pc((*(s--)) + 48);
}

namespace FF {
    char ch, BB[1 << 20], *S = BB, *T = BB;
#define getc() (FF::S==FF::T&&(FF::T=(FF::S=FF::BB)\
+fread(FF::BB,1,1<<20,stdin),FF::S==FF::T)?(exit(0),0):*FF::S++)
#define isd(c) (c>='0'&&c<='9')
    int aa, bb;

    int F() {
        while (ch = getc(), !isd(ch) && ch != '-');
        ch == '-' ? aa = bb = 0 : (aa = ch - '0', bb = 1);
        while (ch = getc(), isd(ch))aa = aa * 10 + ch - '0';
        return bb ? aa : -aa;
    }
}
#define gi FF::F()
#define B 320
int blk[200055][B + 3], bn = 0;
int dt[100055][B + 3], bs[100055][B + 3];
int n, q, b[SZ], a[SZ];
char s[SZ];
int l[SZ], r[SZ];

inline int qry(int t, int x) {
    return dt[t][x / B] + blk[bs[t][x / B]][x % B];
}

vector<pii> eds[SZ];
int seg[SZ];
const int M = 131072;

void sol() {
    for (int i = 1; i <= M + M; ++i) seg[i] = 0;
    for (int i = 1; i <= q; ++i) eds[i].clear();
    for (int i = 1; i <= n; ++i) b[i] = gi, a[i] = 0;
    int cb = n / B;
    bn = 0;
    for (int i = 0; i <= cb; ++i) dt[i][0] = bs[i][0] = 0;
    for (int i = 1; i <= q; ++i) {
        int l, r;
        char ttt;
        while (ttt = getc(), !islower(ttt));
        l = gi, r = gi;
        ::s[i] = ttt;
        ::l[i] = l;
        ::r[i] = r;
        memcpy(dt[i], dt[i - 1], sizeof(int) * (cb + 1));
        memcpy(bs[i], bs[i - 1], sizeof(int) * (cb + 1));
        if (ttt == 'q') continue;
        int bl = l / B, br = r / B;
        if (bl == br) {
            for (int j = l; j <= r; ++j) ++a[j];
            memcpy(blk[++bn], a + bl * B, sizeof(int) * B);
            bs[i][bl] = bn;
        } else {
            for (int j = bl + 1; j < br; ++j) ++dt[i][j];
            for (int j = l; j < bl * B + B; ++j) ++a[j];
            for (int j = br * B; j <= r; ++j) ++a[j];
            memcpy(blk[++bn], a + bl * B, sizeof(int) * B);
            bs[i][bl] = bn;
            memcpy(blk[++bn], a + br * B, sizeof(int) * B);
            bs[i][br] = bn;
        }
    }
    for (int i = 1; i <= n; ++i) {
        int L = 1, bb = b[i];
        for (int j = bb; j <= q; j += bb) {
            int l = L, r = q + 1;
            while (l < r) {
                int m = (l + r) >> 1;
                if (qry(m, i) >= j) r = m;
                else l = m + 1;
            }
            eds[l].pb(pii(i, j / bb));
            if (r > q) break;
            L = l + 1;
        }
    }
    for (int i = 1; i <= q; ++i) {
        vector<pii> &v = eds[i];
        for (unsigned g = 0; g < v.size(); ++g) {
            int x = v[g].fi, y = v[g].se;
            seg[x + M] = y;
            for (int p = (x + M) >> 1; p; p >>= 1)
                seg[p] = seg[p + p] + seg[p + p + 1];
        }
        if (s[i] == 'a') continue;
        int l = ::l[i], r = ::r[i], ans = 0;
        for (l += M - 1, r += M + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
            if (~l & 1) ans += seg[l ^ 1];
            if (r & 1) ans += seg[r ^ 1];
        }
        pint(ans), pc(10);
//        printf("%d\n",ans);
    }
}

int main() {
    while (n = gi, q = gi) sol();
}
