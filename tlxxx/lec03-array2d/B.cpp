#include<iostream>
#include <cstring>

using namespace std;
const int RIGHT = 0, DOWN = 1, LEFT = 2, UP = 3;

int main() {
    int n;
    cin >> n;
    int a[n][n];
    memset(a, 0, sizeof(a));
    int x = 0, y = 0, d = RIGHT;
    a[x][y] = 1;
    for (int i = 2; i <= n * n; i++) {
        int nx = x, ny = y, nd = LEFT;
        switch (d) {
            case RIGHT:
                nx = x, ny = y + 1;
                if (ny < n && a[nx][ny] == 0) {
                    a[nx][ny] = i;
                    nd = RIGHT;
                } else {
                    nx = x, ny = y;
                    nd = DOWN;
                    i--;
                }
                break;
            case DOWN:
                nx = x + 1, ny = y;
                if (nx <n && a[nx][ny] == 0) {
                    a[nx][ny] = i;
                    nd = DOWN;
                } else {
                    nx = x, ny = y;
                    nd = LEFT;
                    i--;
                }
                break;
            case LEFT:
                nx = x, ny = y - 1;
                if (ny >= 0 && a[nx][ny] == 0) {
                    a[nx][ny] = i;
                    nd = LEFT;
                } else {
                    nx = x, ny = y;
                    nd = UP;
                    i--;
                }
                break;
            case UP:
                nx = x - 1, ny = y;
                if (nx >= 0 && a[nx][ny] == 0) {
                    a[nx][ny] = i;
                    nd = UP;
                } else {
                    nx = x, ny = y;
                    nd = RIGHT;
                    i--;
                }
                break;
        }
        x = nx, y = ny, d = nd;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;

}