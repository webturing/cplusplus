//
// Created by jal on 18-7-18.
//

#include <bits/stdc++.h>

using namespace std;
int m, n, x, y, k;
string s;
int a[100][100];

int main() {
    ifstream cin("input.txt");
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    cin >> x >> y >> s >> k;
    int cur_x = x, cur_y = y;
    for (int i = 1; i <= k; i++) {
        if (a[cur_x][cur_y]) {
            a[cur_x][cur_y] = 0;
            if (s[0] == 'U') {
                s = "R";
                cur_y++;
            } else if (s[0] == 'D') {
                s = "L";
                cur_y--;
            } else if (s[0] == 'L') {
                s = "U";
                cur_x--;
            } else if (s[0] == 'R') {
                s = "D";
                cur_x++;
            }
        } else {
            a[cur_x][cur_y] = 1;
            if (s[0] == 'U') {
                s = "L";
                cur_y--;
            } else if (s[0] == 'D') {
                s = "R";
                cur_y++;
            } else if (s[0] == 'L') {
                s = "D";
                cur_x++;
            } else if (s[0] == 'R') {
                s = "U";
                cur_x--;
            }
        }
    }
    cout << cur_x << " " << cur_y << endl;
}