#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
#define CLR(a, b) memset(a,b,sizeof(a))
#define INF 0x3f3f3f3f
#define ll long long
ll mod = 1000003;
ll fac[1000000 + 11] = {1, 1};

void getfac()        //打一个阶乘表
{
    for (int i = 2; i <= 1000000; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }
}

ll quick_mod(ll n, ll m)        //求快速幂
{
    ll ans = 1;
    n %= mod;
    while (m) {
        if (m & 1) {
            ans = ans * n % mod;
        }
        n = n * n % mod;
        m >>= 1;
    }
    return ans;
}

ll C(ll n, ll k)        //费马小定理求逆元
{
    if (k > n) {
        return 0;
    } else {
        return fac[n] * (quick_mod(fac[k] * fac[n - k] % mod, mod - 2)) % mod;
    }
}

ll Lucas(ll n, ll k)       //Lucas定理递归
{
    if (k == 0) {      //递归终止条件
        return 1;
    } else {
        return C(n % mod, k % mod) * Lucas(n / mod, k / mod) % mod;
    }
}

ll n;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld %lld", &n, &mod);
        n--;
        getfac();// 暴力打表求1 ~ mod 的阶层%mod
        ll ans = Lucas(2ll * n, n) * quick_mod(n + 1, mod - 2ll) % mod * 2ll % mod;
        printf("%lld\n", ans);
    }
    return 0;
}
/**
 *
 *  题目名称：简单计数

题目描述
有一个n*n的网格，你初始在左下角(0,0)的位置，现在你每次可以向右走一步或者向上走一步，现在你想走到右上角(n,n)的位置，但是你不走到对角线上（即除了端点外不能经过(i,i)这样的坐标）,问你一共有多少种走法，答案对p取模后输出。
程序输入说明
第一行为测试组数T(1≤T≤10),以下T行每行两个整数,n（1≤n≤1000000000）,p(1≤p≤100000),分别是网格的宽度，以及给定的模数,模数保证是质数。
程序输出说明
共打印T行，每一行表示对p取模后的答案。
程序输入样例
2
1 97
2 97
程序输出样例
2
2
*/