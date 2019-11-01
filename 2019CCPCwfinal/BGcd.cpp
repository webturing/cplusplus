#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    ll s = n * (n + 1) / 2;
    for (ll p = 2; p <= s; p++) {
        if (s % p == 0) {
            cout << s / p << endl;
            break;
        }
    }
    return 0;
}