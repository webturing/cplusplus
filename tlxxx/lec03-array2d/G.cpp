#include<iostream>
#include <cstring>

using namespace std;
const int LEI = 9;

int main() {
    int n, m, k;
    while (cin >> n >> m >> k) {
        int a[n][m];
        memset(a, 0, sizeof(a));
        while (k--) {
            int i, j;
            cin >> i >> j;
            a[i][j] = LEI;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == LEI)continue;
                int z = 0;
                for (int x = i - 1; x <= i + 1; x++)
                    for (int y = j - 1; y <= j + 1; y++) {
                        if (x == i && y == j)continue;
                        if (x < 0 || x >= n || y < 0 || y >= m)continue;
                        if (a[x][y] == LEI)++z;
                    }
                a[i][j] = z;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] != LEI)cout << a[i][j];
                else cout << "*";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;

}
