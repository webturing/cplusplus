//
// Created by ubuntu on 18-7-9.
//

#include <bits/stdc++.h>

using namespace std;

int main() {

    ifstream cin("input.txt");
    unsigned int n, m;
    cin >> n >> m;
    unsigned int x, y;
    cin >> x >> y;
    vector<vector<int>> v(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }
    vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] + v[i][j] - sum[i - 1][j - 1];
        }
    }
    cout << sum[x][y] << endl;
}