#include<iostream>
#include <cstring>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    n = n * 2 + 1;
    int a[n][n];
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = max(abs(i - n / 2), abs(j - n / 2));
        }

    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(2) << a[i][j];
        }
        cout << endl;

    }


    return 0;

}
