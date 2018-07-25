#include<bits/stdc++.h>

using namespace std;


const int MOD = 5000011;

int dp[100001][2];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    dp[1][0] = 1;//0 C
    dp[1][1] = 1;//1 B
    for (int i = 2; i <= N; i++) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
        if (i < K + 2) {
            dp[i][1] = 1;
        } else dp[i][1] = (dp[i - K - 1][1] + dp[i - K - 1][0]) % MOD;
    }
    cout << (dp[N][0] + dp[N][1]) % MOD << endl;
    return 0;
}