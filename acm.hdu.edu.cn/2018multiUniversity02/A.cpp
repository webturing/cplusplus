#include<bits/stdc++.h>

using namespace std;

const long long MOD = 998244353LL;


int main() {
    long long L = 0, R = 0, l, r;
    for (int n; cin >> n;) {
        for (int i = 0; i <= n; i++) {
            cin >> l >> r;
            L += l, R += r;

        }
    }
    long long p = L + R;
    if (p & 1)
        p--;
    cout << (p >> 1) % MOD << endl;


    return 0;
}