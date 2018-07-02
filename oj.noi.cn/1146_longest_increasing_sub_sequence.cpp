//
// Created by ubuntu on 18-7-2.
//

#include <bits/stdc++.h>

const int N = 5001;
int a[N];
int dp[N + 1];
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dp[0] = 1;//表示以x[0]为子序列最右边的长度位1
    int i, j;
    for (i = 1; i < n; i++) {
        dp[i] = 1;//初始化每种情况最小值为1
        for (j = 0; j < i; j++) {
            if (a[i] >= a[j] && dp[j] + 1 > dp[i])//从0-i进行扫描,查找边界小于当前最优解长度相等的解优化最优解
                dp[i] = dp[j] + 1;//如果允许子序列相邻元素相同  x[i]>=x[j]&&dp[j]+1>dp[i];
        }
    }
    cout << *max_element(dp, dp + n) << endl;
}