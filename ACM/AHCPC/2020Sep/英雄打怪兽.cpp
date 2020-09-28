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
 * 题目名称：英雄打怪兽

题目描述
在遥远的地方有一个怪兽和一位英雄，英雄带着a支箭去挑战这个怪兽，怪兽的血量为b，英雄的每次射击能扣除怪兽的一点血量，如果怪兽的血量小于等于0，那么英雄就挑战成功。令人烦恼的是，英雄每次射击后，怪兽都会生气，向英雄发起反击，有50%的概率使得英雄掉落一支箭，现在请问英雄挑战成功的概率是多少？输出一个保留5位小数的浮点数
程序输入说明
两个数a，b(0<a<10000,0<b<5000)
程序输出说明
一个保留5位小数的浮点数，表示英雄挑战成功的概率
程序输入样例
10 5
程序输出样例
1.00000
*/