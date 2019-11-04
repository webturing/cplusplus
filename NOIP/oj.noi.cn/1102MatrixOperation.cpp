#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> v[i][j];
    int q;
    cin >> q;
    while (q--) {
        string op;
        int x, y;

        cin >> op >> x >> y;
        if (op == "Q") {
            cout << v[x][y] << endl;
        } else {
            swap(v[x], v[y]);
        }

    }
    return 0;
}