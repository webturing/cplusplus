#include<iostream>
#include <cstring>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0)break;
        int a[n][n];
        memset(a, 0, sizeof(a));
        int x = n - 1, y = n / 2;
        a[x][y] = 1;
        for (int i = 2; i <= n * n; i++) {
            int nx = (x + 1) % n;
            int ny = (y + 1) % n;
            if (a[nx][ny] > 0) {
                nx = (x - 1 + n) % n;
                ny = y;
            }
            a[nx][ny] = i;
            x = nx, y = ny;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;

}
