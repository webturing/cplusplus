#include <bits/stdc++.h>

using namespace std;
using LL = int;

inline bool prime(LL n) {
    if (n == 0 || n == 1) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
    size_t l, k;
    string s;
    cin >> l >> k >> s;
    assert(s.size() == l);
    if (s.size() < k) {
        cout << 404;
        return 0;
    }
    for (size_t i = 0; i <= s.size() - k; i++) {
        if (prime(stoi(s.substr(i, k)))) {
            cout << stoi(s.substr(i, k));
            return 0;
        }
    }
    cout << 404;
    return 0;
}