#include<iostream>
#include <cstring>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n][n];
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++)a[i][i] = a[i][0] = 1;
    for (int i = 2; i < n; i++) {
        for (int j = 1; j < i; j++) {
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;

}
