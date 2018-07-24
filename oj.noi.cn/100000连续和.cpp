#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long LL;
const int MOD = 999999;

LL mpower(LL a, int n) {
    a %= MOD;
    if (a == 1 || n == 0)
        return 1LL;
    if (a == 0 || n == 1)
        return a;
    if (n & 1) {
        return (a * mpower((a * a) % MOD, n / 2)) % MOD;
    } else {
        return mpower((a * a) % MOD, n / 2);
    }
}

int main() {
    ifstream cin("input.txt");
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &e:a)cin >> e;

    vector<int> s(n);

    s[0] = a[0];
    for (int i = 1; i < n; i++)
        s[i] = s[i - 1] + a[i];
    sort(s.begin(), s.end());

    LL ans = (upper_bound(s.begin(), s.end(), 0) - lower_bound(s.begin(), s.end(), 0)) % MOD;

    auto i = s.begin();
    while (i != s.end()) {
        int value = *i;
        auto p = upper_bound(i, s.end(), value);
        int x = p - i;
        ans = (ans + (1LL * x * (x - 1) / 2)) % MOD;
        i = p;
    }
    cout << ans << endl;


    return 0;
}