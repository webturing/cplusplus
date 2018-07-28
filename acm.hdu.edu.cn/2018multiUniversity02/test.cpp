#include<bits/stdc++.h>

using namespace std;


int main() {
    for (int n = 2; n <= 5; n++)
        for (int m = 2; m <= 5; m++) {
            cout << endl;
            cout << n << "X" << m << endl;
            vector<vector<int>> a(n, vector<int>(m, 0));
            map<pair<int, int>, int> mp;
            for (int i = 0; i < (1 << (n * m)); i++) {
                int k = i;
                for (int j = 0; j < n * m; j++)
                    a[j / m][j % m] = k % 2, k /= 2;
                int row = 0, col = 0;
                for (int j = 0; j < n; j++)
                    if (count(a[j].begin(), a[j].end(), 1) == m)++row;
                for (int j = 0; j < m; j++) {
                    int t = 0;
                    for (int y = 0; y < n; y++)
                        t += a[y][j];
                    if (t == n)++col;

                }
                mp[make_pair(row, col)]++;
            }
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= m; j++)
                    cout << fixed << setw(8) << mp[make_pair(i, j)] << " ";
                cout << endl;
            }
        }

}