//
// Created by jal on 18-7-22.
//

#include <bits/stdc++.h>

using namespace std;
int n, m;

int main() {
    ifstream cin("input.txt");
    cin >> n >> m;
    vector<vector<int>> dp(n + 1);
    for (auto &i:dp) {
        i.resize(n + 1);
    }
    dp[1][1] = dp[2][1] = dp[2][2] = 1;
    set<pair<int, int>> s;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        s.insert(make_pair(x, y));
    }
    for (int i = 3; i <= n; i++) {
        if (s.find(make_pair(i - 1, 1)) == s.end()) {
            dp[i][1] = dp[i - 1][1];
        } else {
            dp[i][1] = 0;
        }

        for (int j = 2; j < i; j++) {
            pair<int, int> left_up(i - 1, j - 1), up(i - 1, j);
            int temp = 0;
            if (s.find(left_up) == s.end()) {
                temp += dp[i - 1][j - 1];
            }
            if (s.find(up) == s.end()) {
                temp += dp[i - 1][j];
            }
            dp[i][j] += temp;
        }
        if (s.find(make_pair(i - 1, i - 1)) == s.end()) {
            dp[i][i] = dp[i - 1][i - 1];
        } else {
            dp[i][i] = dp[i - 1][i - 1] = 0;
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += dp[n][i];
    }
    cout << sum << endl;
    return 0;
}