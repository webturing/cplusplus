#include <bits/stdc++.h>

using namespace std;

const int MOD = 2005;
int f[1000000][2][2] = {0};

int main() {
    int n;
    cin >> n;
    if (n < 3) {
        cout << (1 << n) << endl;
        return 0;
    }

    f[2][0][0] = f[2][0][1] = f[2][1][0] = f[2][1][1] = 1;
    for (int i = 3; i <= n; i++) {
        f[i][0][0] = (f[i - 1][0][0] + f[i - 1][0][1]) % MOD;
        f[i][0][1] = (f[i - 1][1][1] + f[i - 1][1][0]) % MOD;
        f[i][1][0] = f[i - 1][0][0];
        f[i][1][1] = f[i - 1][1][0];
    }
    cout << (f[n][0][0] + f[n][0][1] + f[n][1][0] + f[n][1][1]) % MOD << endl;
    return 0;
}
