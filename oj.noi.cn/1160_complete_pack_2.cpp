//
// Created by ubuntu on 18-7-9.
//

#include <bits/stdc++.h>

using namespace std;
const int N = 1001, T = 101, MAX = 101;
int w[T], v[T];
int dp[N];

int main() {
    ifstream cin("input.txt");
    int n, t;
    cin >> n >> t;
    for (int i = 1; i <= t; i++) {
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i <= t; i++) {
        for (int j = w[i]; j <= n; j++) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[n] << endl;
}