#include<bits/stdc++.h>

using namespace std;
const int UP = 1, DOWN = 2, LEFT = 3, RIGHT = 4, RIGHT_UP = 5, LEFT_DOWN = 6;

int main() {
    int n = 5;
    int a[n][n];
    memset(a, 0, sizeof(a));
    int x = 0, y = 0, d = DOWN, k = 1;
    a[x][y] = k++;
    while (k <= n * n) {
        int nx = x, ny = y;
        switch (d) {
            case DOWN:
                nx = x + 1, ny = y;
                if (nx < n) {
                    a[x = nx][y = ny] = k++;
                    if (y == n - 1) { d = LEFT_DOWN; }
                    else { d = RIGHT_UP; }
                } else {
                    d = RIGHT;
                }
                break;
            case LEFT_DOWN:
                nx = x + 1, ny = y - 1;
                if (nx < n && ny >= 0) {
                    a[x = nx][y = ny] = k++;
                    d = LEFT_DOWN;
                } else {
                    d = DOWN;
                }
                break;
            case RIGHT_UP:
                nx = x - 1, ny = y + 1;
                if (nx >= 0 && ny < n) {
                    a[x = nx][y = ny] = k++;
                    d = RIGHT_UP;
                } else {
                    d = RIGHT;
                }
                break;
            case RIGHT:
                nx = x, ny = y + 1;
                if (ny < n) {
                    a[x = nx][y = ny] = k++;
                    if (x == n - 1) { d = RIGHT_UP; }
                    else { d = LEFT_DOWN; }
                } else {
                    d = DOWN;
                }
                break;

        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(3) << a[i][j];
        }
        cout << endl;
    }
    return 0;
}
