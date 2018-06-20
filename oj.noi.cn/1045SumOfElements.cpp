#include <bits/stdc++.h>

using namespace std;
const int ROWS = 4;
const int COLS = 4;

int main(int argc, char const *argv[]) {
    //ifstream cin("input.txt");
    vector<vector<int> > A(ROWS, vector<int>(COLS));
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            cin >> A[i][j];
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < ROWS; i++) {
        sum1 += A[i][i];
        sum2 += A[ROWS - 1 - i][i];
    }
    cout << sum1 << " " << sum2 << endl;
    return 0;
}