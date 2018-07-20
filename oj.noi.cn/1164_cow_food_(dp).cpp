//
// Created by jal on 18-7-20.
//

#include <bits/stdc++.h>

using namespace std;
int n;
int a[2001];
int dp[2001][2001];

int main() {
    ifstream cin("input.txt");
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        dp[1][i] = a[i] * n;//从ｉ为起点的食物，只剩一天的时候，价值为dp[1][i];
    }
    for (int r = 2; r <= n; r++) {//从i为起点的食物，只剩r天的时候，价值为dp[r][i];
        for (int i = r - 1; i < n; i++) {
            dp[r][i] = max(dp[r - 1][i] + a[i - r + 1] * (n - r + 1), dp[r - 1][i - 1] + a[i] * (n - r + 1));
        }
    }
    cout << dp[n][n - 1] << endl;
}