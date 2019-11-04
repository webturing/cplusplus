#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100 + 10;


int main() {
    ifstream cin("input.txt");
    int r, c, n;
    vector<vector<char>> a(MAXN, vector<char>(MAXN, '0'));
    cin >> r >> c >> n;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            cin >> a[i][j];

    while (n--) {
        vector<vector<char>> b(a);
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++) {
                if (a[i][j] == 'R') {
                    if (a[i - 1][j] == 'P') b[i][j] = a[i - 1][j];
                    if (a[i][j + 1] == 'P') b[i][j] = a[i][j + 1];
                    if (a[i + 1][j] == 'P') b[i][j] = a[i + 1][j];
                    if (a[i][j - 1] == 'P') b[i][j] = a[i][j - 1];
                }
                if (a[i][j] == 'S') {
                    if (a[i - 1][j] == 'R') b[i][j] = a[i - 1][j];
                    if (a[i][j + 1] == 'R') b[i][j] = a[i][j + 1];
                    if (a[i + 1][j] == 'R') b[i][j] = a[i + 1][j];
                    if (a[i][j - 1] == 'R') b[i][j] = a[i][j - 1];
                }
                if (a[i][j] == 'P') {
                    if (a[i - 1][j] == 'S') b[i][j] = a[i - 1][j];
                    if (a[i][j + 1] == 'S') b[i][j] = a[i][j + 1];
                    if (a[i + 1][j] == 'S') b[i][j] = a[i + 1][j];
                    if (a[i][j - 1] == 'S') b[i][j] = a[i][j - 1];
                }
            }
        copy(b.begin(), b.end(), a.begin());
    }

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++)
            cout << a[i][j];
        cout << endl;
    }

    return 0;
}