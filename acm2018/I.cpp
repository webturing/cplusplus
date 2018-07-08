#include<bits/stdc++.h>

using namespace std;

int main() {
    ifstream cin("input.txt");
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        vector<vector<int>> sum(a);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++)
                sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + a[i][j];
        }
        int maxk = 1;
        for (int x2 = 1; x2 <= n; x2++)
            for (int x1 = x2; x1 <= n; ++x1)
                for (int y2 = 1; y2 <= m; ++y2)
                    for (int y1 = y2; y1 <= m; ++y1) {
                        int outer = sum[x1][y1] - sum[x1][y2 - 1] - sum[x2 - 1][y1] + sum[x2 - 1][y2 - 1];
                        int X1 = x1 - 1, Y1 = y1 - 1, X2 = x2 + 1, Y2 = y2 + 1;
                        int inner = sum[X1][Y1] - sum[X1][Y2 - 1] - sum[X2 - 1][Y1] + sum[X2 - 1][Y2 - 1];
                        if (outer - inner == 2 * (y1 - y2 + x1 - x2 + 2) - 4) {
                            int k = (y1 - y2 + 1) * (x1 - x2 + 1);
                            if (k > maxk) {
                                maxk = k;
                                //  cout << x2 << y2 << x1 << y1 << endl;
                            }
                        }
                    }
        cout << maxk << endl;

    }
    return 0;
}
/**
 *
 Sample Input
1
5 5
0 1 0 1 0
1 1 1 1 0
1 1 0 1 1
1 1 1 1 1
0 1 1 1 1

*/