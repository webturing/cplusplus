#include<bits/stdc++.h>

using namespace std;


const int MOD = 9901;
const int N = 305;
const int M = 105;

int dp[N][M];//dp[i][j]表示节点为i，高度小于等于j的方案数
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    dp[0][0] = 1;

    for (int j = 1; j < M; j++)dp[1][j] = 1;
    int n, m;
    cin >> n >> m;
    for (int i = 3; i < N; i += 2) {
        for (int j = 1; j < M; j++) {
            for (int k = 1; k <= i - 2; k += 2) {
                dp[i][j] = (dp[i][j] + dp[k][j - 1] * dp[i - 1 - k][j - 1]) % MOD;
            }
        }
    }

    cout << (dp[n][m] - dp[n][m - 1] + MOD) % MOD << endl;
    return 0;
} 