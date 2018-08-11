#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> w(7, 0);
    int M[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
    vector<int> D;
    int cnt = 0;
    for (int y = 1900; y < 1900 + n; y++) {
        int leap = (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
        for (int i = 1; i <= 12; i++) {
            for (int j = 1; j <= M[leap][i]; j++) {
                if (j == 13) {
                    w[cnt % 7]++;
                }
                ++cnt;
            }
        }
    }
    for (int i = 5; i < 5 + 7; i++) cout << w[i % 7] << " ";
    cout << endl;
    return EXIT_SUCCESS;
}