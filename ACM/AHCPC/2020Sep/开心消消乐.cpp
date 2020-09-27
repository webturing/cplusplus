#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <iomanip>

#define rep(i, x, n) for(int i=x;i<n;i++)
#define repd(i, x, n) for(int i=x;i<=n;i++)
using namespace std;
#define ll long long
const int maxn = 510;
int n, mod;
int a[maxn];
int b[maxn][maxn];
int dp[maxn][maxn];

int main() {
    //freopen("D:\\code\\text\\input.txt","r",stdin);
    //freopen("D:\\code\\text\\output.txt","w",stdout);
    scanf("%d %d", &n, &mod);
    repd(i, 1, n) {
        scanf("%d", &a[i]);
        b[i][i] = a[i];
    }
    repd(i, 1, n) {
        repd(j, i, n) {
            dp[i][j] = j - i + 1;
        }
    }
    repd(len, 2, n) {
        repd(i, 1, n - len + 1) {
            int j = i + len - 1;
            repd(k, i, i + len - 2) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                if (dp[i][k] == 1 && dp[k + 1][j] == 1 && (b[i][k] == b[k + 1][j])) {
                    dp[i][j] = 1;
                    b[i][j] = (b[i][k] + b[k + 1][j]) % mod;
                }
            }
        }
    }
    printf("%d\n", dp[1][n]);
    return 0;
}   /**
 * 题目名称：开心消消乐

题目描述
a1a2…an是一个长度为n(1≤n≤500)的数组，给定一个模数m(1≤m≤1000)，现在可以对数组进行任意次操作，每次可以选择一个下标i (1≤i<n),且ai=ai+1，我们可以将这两个数替换为(ai+ai+1)%m。问：可以得到数组最短的长度是多少？
程序输入说明
单组数据，第一行两个整数n,m,分别表示数组长度和给定的模数,第二行n个整数 表示a1a2…an，(0<=ai<m)。
程序输出说明
共输出一行，输出经过若干次操作，数组可以达到的最短长度。
程序输入样例
5 5
3 4 2 1 1
程序输出样例
1
数据范围及提示
3 4 2 1 1 -> 3 4 2 2 -> 3 4 2 2 -> 3 4 2 2 -> 3 4 4 -> 3 4 4 -> 3 3 -> 3 3 -> 1
最后就剩下一个数字，长度为1
 */
