#include<iostream>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int s = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || i + j == n - 1) {
                s += a[i][j];
            }
        }
    }
    cout << s << endl;
    return 0;

}
