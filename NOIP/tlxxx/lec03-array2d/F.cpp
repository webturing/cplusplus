#include<iostream>

using namespace std;
const int ROW = 3;
const int COL = 4;

int main() {
    int a[ROW][COL];
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            cin >> a[i][j];

    int mi = 0, mj = 0;
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++) {
            if (a[i][j] > a[mi][mj]) {
                mi = i;
                mj = j;
            }
        }
    cout << a[mi][mj] << endl
         << mj + 1 << endl
         << mi + 1 << endl;
    return 0;

}
