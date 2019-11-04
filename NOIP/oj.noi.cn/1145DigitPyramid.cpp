#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream cin("input.txt");
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++) { cin >> v[i][j]; }
    vector<vector<int>> dp(v);
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + v[i][j];
        }
    }
    cout << dp[0][0] << endl;

    return EXIT_SUCCESS;
}