#include<bits/stdc++.h>

using namespace std;
typedef long long LL;


#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)

#define dbg(x...) do { cout << "\033[32;1m" << #x << " -> "; err(x); } while (0)

void err() { cerr << "\033[39;0m" << endl; }

template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) {
    for (auto v: a) cerr << v << ' ';
    err(x...);
}

template<typename T, typename... A>
void err(T a, A... x) {
    cerr << a << ' ';
    err(x...);
}

template<typename T>
inline T read() {
    T x;
    cin >> x;
    return x;
}

const int M = 10;

struct RMQ {
    int f[22][M];

    inline int highbit(int x) { return 31 - __builtin_clz(x); }

    void init(int *v, int n) {
        FOR (i, 0, n) f[0][i] = v[i];
        FOR (x, 1, highbit(n) + 1)FOR (i, 0, n - (1 << x) + 1)f[x][i] = min(f[x - 1][i], f[x - 1][i + (1 << (x - 1))]);
    }

    int get_min(int l, int r) {
        assert(l <= r);
        int t = highbit(r - l + 1);
        return min(f[t][l], f[t][r - (1 << t) + 1]);
    }
} rmq;

int main() {
    int a[10];
    FOR(i, 0, 10)a[i] = rand() % 10;
    FOR(i, 0, 10)cout << a[i] << " ";
    cout << endl;
    rmq.init(a, 10);
    while (1) {
        int l(read<int>()), r(read<int>());
        if (cin.fail())break;
        cout << rmq.get_min(l, r) << endl;
    }
    return 0;
}
/**
 * RMQ问题
?RMQ（Range Minimum/Maximum Query），即区间最值查询。对于长度为n的数列arr，回答若干询问Q(i,j)，返回数列arr中下标在i,j之间的最大/小值。如果只有一次询问，那一遍for就可以搞定，但是如果有多次询问就无法在很快的时间处理出来。

ST算法
?ST算法是一个在线算法，它可以在O(nlogn)时间内进行预处理，然后在O(1)的时间内回答每个查询，假设现在的数组为arr[] = {1,3,6,7,4,2,5,9}，算法步骤如下：

一、预处理（以处理区间最小值为例）
?dpi表示从第i位开始连续2^j^个数（也就是到i+2^j^-1）中的最小值。例如dp2表示从第2个数开始，连续2个数的最小值，即3,6之间的最小值，即dp2=3，从dp数组的含义我们就知道，dpi=arr[i]（下标均是从1开始），初值有了，剩下的就是状态转移方程。首先把dpi平均分成两段（因为一定是偶数个数字），从i到i+2^j-1^-1为一段，i+2^j-1^到i+2^j^-1为一段（每段长度都为2^j-1^）。假设i=1,j=3时就是1,3,6,7和4,2,5,9这两段。dpi就是这两段最大值的最大值。于是得到了状态转移方程式dpi = max(dpi,dpi+2^j-1^)

for(int i = 1;i <= n;i++)
    dp[i][0] = arr[i];
for(int j = 1;(1 << j) <= n;j++)
    for(int i = 1;i + (1 << j) - 1 <= n;i++)
        dp[i][j] = Math.min(dp[i][j-1],dp[i + (1<<(j - 1))][j-1]);
二、查询
?假设我们需要查询区间[L,R]中的最小值，令k=log~2~(R-L+1)，则区间[L,R]的最小值res=min(dpL,dpR-(1<<k)+1)，为什么这样就可以保证区间最值？dpL维护的是[L,L+2^k^-1]，dpL[k]维护的是[R-2^k^+1,R]，因此只要证明R-2^k^+1 ≤ l+2^k^-1即可，这里证明省略

int k = (int) (Math.log(r - l + 1) / Math.log(2));
int min = Math.min(dp_min[l][k],dp_min[r - (1 << k) + 1][k]);
举个栗子
?L=4,R=6，此时k=log~2~(R-L+1)=log~2~3=1，所以RMQ(4,6)=min(dp4,dp5)=min(4,2)=2，很容易看出来答案是正确的
 */
