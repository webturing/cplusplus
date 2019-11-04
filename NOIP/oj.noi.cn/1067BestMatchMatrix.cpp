#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream cin("input.txt");
    int m, n;
    cin >> m >> n;
    vector<vector<int>> A(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)for (int j = 0; j < n; j++)cin >> A[i][j];
    int r, s;
    cin >> r >> s;
    vector<vector<int>> B(r, vector<int>(s, 0));
    for (int i = 0; i < r; i++)for (int j = 0; j < s; j++)cin >> B[i][j];
    int minDiff = 0xfffff, x0, y0;
    for (int i = 0; i <= m - r; i++)
        for (int j = 0; j <= n - s; j++) {
            int diff = 0;
            for (int x = i; x < r + i; x++)
                for (int y = j; y < s + j; y++) {
                    diff += abs(A[x][y] - B[x - i][y - j]);
                }
            if (diff < minDiff) {
                minDiff = diff;
                x0 = i;
                y0 = j;
                cerr << minDiff << x0 << y0 << endl;
            }
        }
    for (int x = x0; x < r + x0; x++) {
        for (int y = y0; y < s + y0; y++) {
            cout << A[x][y] << " ";
        }
        cout << endl;

    }
    return EXIT_SUCCESS;
}