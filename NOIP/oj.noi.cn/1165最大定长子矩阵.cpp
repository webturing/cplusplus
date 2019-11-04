#include<bits/stdc++.h>

using namespace std;
const int maxn = 1001;
int a[maxn][maxn];
int sum[maxn][maxn];

int main() {
    ios::sync_with_stdio(false);
    long long start = clock();
    ifstream cin("input.txt");
    int n, m, r, c;
    cin >> n >> m >> r >> c;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + a[i][j];
    }
    int maxk = 1;
    for (int x2 = 1; x2 <= n - r + 1; x2++)
        for (int y2 = 1; y2 <= m - c + 1; ++y2) {
            int x1 = x2 + r - 1;
            int y1 = y2 + c - 1;
            int outer = sum[x1][y1] - sum[x1][y2 - 1] - sum[x2 - 1][y1] + sum[x2 - 1][y2 - 1];
            maxk = max(maxk, outer);
        }
    cout << maxk << endl;
    long long end = clock();
    cerr << 1.0 * (end - start) / CLOCKS_PER_SEC << endl;

    return 0;
}