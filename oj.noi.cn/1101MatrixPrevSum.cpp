#include<bits/stdc++.h>

using namespace std;

int main() {
    ifstream cin("input.txt");
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    vector<vector<int>> sum(a);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + a[i][j];
    }

    int q;
    cin >> q;
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x2 >> y2 >> x1 >> y1;
        int s = 0;
        cout << sum[x1][y1] - sum[x1][y2 - 1] - sum[x2 - 1][y1] + sum[x2 - 1][y2 - 1] << endl;
    }
    return 0;
}