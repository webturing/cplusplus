//
// Created by jal on 18-7-20.
//

#include <bits/stdc++.h>

using namespace std;
int dp[31][2][2];

int main() {
    int n;
    cin >> n;

    dp[2][0][0] = dp[2][0][1] = dp[2][1][0] = dp[2][1][1] = 1;
    for (int i = 3; i <= n; i++) {
        dp[i][0][0] = dp[i - 1][0][0] + dp[i - 1][0][1];
        dp[i][0][1] = dp[i - 1][1][0] + dp[i - 1][1][1];
        dp[i][1][0] = dp[i - 1][0][0] + dp[i - 1][0][1];
        dp[i][1][1] = dp[i - 1][1][0];
    }
    cout << (1 << n) - accumulate(dp[n][0], dp[n][0] + 4, 0) << endl;
}