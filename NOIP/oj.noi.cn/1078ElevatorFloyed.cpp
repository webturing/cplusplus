#include <bits/stdc++.h>

using namespace std;
const int inf = 1e6;

int main() {
    ifstream cin("input.txt");
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)cin >> v[i];
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, inf));
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
        if (i + v[i] <= n)dp[i][i + v[i]] = 1;
        if (i - v[i] >= 1)dp[i][i - v[i]] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int m = dp[i][j];
            for (int k = 1; k <= n; k++) {
                m = min(m, dp[i][k] + dp[k][j]);
            }
            dp[i][j] = m;
        }
    }
    if (dp[a][b] == inf) { cout << -1 << endl; }
    else { cout << dp[a][b] << endl; }
    return 0;
}