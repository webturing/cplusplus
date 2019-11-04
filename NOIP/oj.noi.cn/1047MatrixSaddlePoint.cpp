#include <bits/stdc++.h>

using namespace std;
const int ROWS = 5;
const int COLS = 5;
vector<vector<int> > A(ROWS, vector<int>(COLS));

bool findSaddle(int &x, int &y) {
    for (int i = 0; i < ROWS; i++) {
        int my = max_element(A[i].begin(), A[i].end()) - A[i].begin();
        vector<int> v(ROWS);
        for (int j = 0; j < ROWS; j++)
            v[j] = A[j][my];
        int mx = min_element(v.begin(), v.end()) - v.begin();
        if (mx == i) {
            x = mx;
            y = my;
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[]) {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            cin >> A[i][j];
    int x, y;
    if (findSaddle(x, y)) {
        cout << x + 1 << " " << y + 1 << " " << A[x][y] << endl;
    } else {
        cout << "not found" << endl;
    }
    return 0;
}