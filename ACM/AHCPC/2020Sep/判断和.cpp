#include<bits/stdc++.h>

using namespace std;
#define rep(i, a, n) for (int i=a;i<=n;++i)
#define per(i, n, a) for (int i=n;i>=a;--i)
#define sz(x) ((int)(x).size())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define lson l,mid,p<<1
#define rson mid+1,r,p<<1|1
typedef pair<int, int> pii;
#define ll long long
const int inf = 1e9;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
ll n, a[44], k;

bool solve() {
    set<ll> x;
    int s = n / 2;
    for (int i = 0; i < (1 << s); i++) {
        ll ret = 0;
        for (int j = 0; j < s; j++)
            if (i >> j & 1) {
                ret += a[j];
            }
        if (ret == k) return true;
        if (ret < k) x.insert(ret);
    }
    for (int i = 0; i < (1 << (n - s)); i++) {
        ll ret = 0;
        for (int j = 0; j < n - s; j++)
            if (i >> j & 1) {
                ret += a[j + s];
            }
        if (ret == k) return true;
        if (ret < k) {
            auto it = x.lower_bound(k - ret);
            if (it != x.end() && *it == k - ret) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    //ios::sync_with_stdio(false);
    //freopen("in","r",stdin);
    scanf("%d", &n);
    rep(i, 0, n - 1) scanf("%lld", &a[i]);
    scanf("%lld", &k);
    if (solve()) {
        puts("YES");
    } else puts("NO");
    return 0;
}
/**
 * 题目名称：判断和

题目描述
输入n个数ai(0<ai<1e9)和一个数k(0<k<1e9)，问是否能从n个数中选择一些数，使得他们的和为k，如果可以输出"YES"，否则输出"NO"。
程序输入说明
首先是一个数n(0<n<=40)，接下来是n个数ai(0<ai<1e9)，最后是一个数k(0<k<1e9)
程序输出说明
如果可以输出"YES"，否则输出"NO"。
程序输入样例
2
3 5
8
程序输出样例
YES
*/