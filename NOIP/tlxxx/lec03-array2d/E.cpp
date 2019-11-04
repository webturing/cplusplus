#include<iostream>

using namespace std;
const int ROW = 2;
const int COL = 3;

int main() {
    int a[ROW][COL], b[COL][ROW];
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            cin >> a[i][j];

    for (int i = 0; i < COL; i++)
        for (int j = 0; j < ROW; j++)
            b[i][j] = a[j][i];
    for (int i = 0; i < COL; i++) {
        for (int j = 0; j < ROW; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    return 0;

}
