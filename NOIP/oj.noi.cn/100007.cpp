#include<bits/stdc++.h>

using namespace std;
int n, k, f[2][100];//f[1][i]保存第i位不为0的方案数

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> n >> k;         //非0的k进制数有k-1种
    k--;
    f[1][0] = 1;                        //预处理第0位
    for (int i = 1; i <= n; i++) {
        f[0][i] = f[1][i - 1];
        f[1][i] = k * (f[0][i - 1] + f[1][i - 1]);
    }
    cout << f[1][n] << endl;
    return 0;
}
