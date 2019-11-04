//
// Created by ubuntu on 18-7-9.
//

#include <bits/stdc++.h>

using namespace std;
const int N = 10;
int n;
int sum = 0;
int a[N][N], book[N][N];
int nxt[8][2] = {{0,  1},
                 {0,  -1},
                 {1,  0},
                 {-1, 0},
                 {1,  -1},
                 {1,  1},
                 {-1, 1},
                 {-1, -1}};

void dfs(int x, int y) {
    if (x == 0 && y == n - 1) {
        sum++;
        return;
    }

    for (int i = 0; i < 8; i++) {
        int tx = x + nxt[i][0];
        int ty = y + nxt[i][1];
        if (tx >= n || ty >= n || tx < 0 || ty < 0 || a[tx][ty] == 1 || book[tx][ty] == 1) {
            continue;
        }
        book[tx][ty] = 1;
        dfs(tx, ty);
        book[tx][ty] = 0;
    }
}

int main() {
    ifstream cin("input.txt");//26544
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    book[0][0] = 1;
    dfs(0, 0);
    cout << sum << endl;
}