#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int T;
    long long a, b, c, n, m;
    cin >> T;
    while (T--) {
        cin >> n >> a;
        if (n >= 3 || n == 0) {
            cout << "-1 -1" << endl;
            continue;
        }
        if (n == 1) {
            cout << a << " " << 2 * a << endl;
            continue;
        }
        if (a % 2 == 1) {
            n = a / 2;
            b = 2 * n * n + 2 * n;
            c = 2 * n * n + 2 * n + 1;
            cout << b << " " << c << endl;
            continue;
        }
        m = a;
        n = 1;
        cout << m * m - n * n << " " << m * m + n * n << endl;
    }
    return 0;
}