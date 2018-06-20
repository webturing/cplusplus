#include <bits/stdc++.h>

using namespace std;
const int SOUTH = 0;
const int EAST = 1;
const int SOUTHEAST = 2;
const int NORTHWEST = 3;

struct {
    int drow;
    int dcol;
} direct[] = {{1,  0},
              {0,  1},
              {-1, 1},
              {1,  -1}};

const int N = 100;

int a[N][N];

int main() {
    int n, val = 1;
    cin >> n;
    int row = 0, col = 0, next = SOUTH;
    a[row][col] = val;

    while (row != n - 1 || col != n - 1) {
        val++;
        row += direct[next].drow;
        col += direct[next].dcol;
        a[row][col] = val;

        if (next == SOUTH && col == 0)
            next = SOUTHEAST;
        else if (next == SOUTH && col == n - 1)
            next = NORTHWEST;
        else if (next == EAST && row == 0)
            next = NORTHWEST;
        else if (next == EAST && row == n - 1)
            next = SOUTHEAST;
        else if (next == SOUTHEAST && col == n - 1)
            next = SOUTH;
        else if (next == SOUTHEAST && row == 0)
            next = EAST;
        else if (next == SOUTHEAST && row != 0)
            next = SOUTHEAST;
        else if (next == NORTHWEST && row == n - 1)
            next = EAST;
        else if (next == NORTHWEST && col != 0)
            next = NORTHWEST;
        else if (next == NORTHWEST && col == 0)
            next = SOUTH;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

    return 0;
}