#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 10;
typedef long long ll;

int main() {
    int t;
    scanf("%d", &t);
    ll n;
    while (t--) {
        scanf("%lld", &n);
        n <<= 1;
        n |= 1;
        // cout << n << endl;
        printf("%lld\n", ((n - 1) * (n - 2)) * n / 3 / 2 - ((n / 2 - 1) * (n / 2) / 2 * n));
    }

    return 0;
}


/**
 * 题目名称：三角形计数

题目描述
给定一个n,问在凸正2n+1边形中顶点在凸正2n+1边形上的不同的锐角三角形有多少个，多边形顶点标号为A1A2A3…A2n+1,两个三角形不同当且仅当顶点标号不同。
程序输入说明
多组数据，第一行输入数据组数T（1 < T < 100000）,后面T行，每一行给出一个n（1 < n < 100000）。
程序输出说明
共输出T行，每一行输出不同锐角三角形的个数。
程序输入样例
2
2
3
程序输出样例
5
14
 */
