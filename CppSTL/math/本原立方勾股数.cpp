#include <bits/stdc++.h>

using namespace std;
using LL=long long;


template<typename T=int>
inline T read() {
    T x;
    cin >> x;
    return x;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    const int N = 100;
    vector<LL> f(N + 1);
    for (int i = 1; i <= N; i++)f[i] = 1LL * i * i * i;
    copy(f.begin(), f.end(), ostream_iterator<LL>(cout, " "));
    cout << endl;
    for (int a = 1; a <= N; a++)
        for (int b = a; b <= N; b++)
            for (int c = b; c <= N; c++) {
                auto p = lower_bound(f.begin(), f.end(), f[a] + f[b] + f[c]);
                if (*p == f[a] + f[b] + f[c] and __gcd(a, __gcd(b, c)) == 1)
                    cout << a << "^3+" << b << "^3+" << c << "^3=" << p - f.begin() << "^3" << endl;

            }


    return 0;
}
