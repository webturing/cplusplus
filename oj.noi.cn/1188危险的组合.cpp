#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long LL;
LL f[31][2][2] = {0};

int main() {
    int n;
    cin >> n;
    if (n < 3) {
        cout << 0 << endl;
        return 0;
    }

    f[3][0][0] = f[3][0][1] = f[3][1][0] = 2, f[3][1][1] = 1;
    for (int i = 4; i <= n; i++) {
        f[i][0][0] = f[i - 1][0][0] + f[i - 1][0][1];
        f[i][0][1] = f[i - 1][1][1] + f[i - 1][1][0];
        f[i][1][0] = f[i - 1][0][0] + f[i - 1][0][1];
        f[i][1][1] = f[i - 1][1][0];
    }
    cout << (1LL << n) - (f[n][0][0] + f[n][0][1] + f[n][1][0] + f[n][1][1]) << endl;
    return 0;
}
