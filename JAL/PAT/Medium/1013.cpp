#include <bits/stdc++.h>

using namespace std;

using LL = long long;

template<typename T = int>
inline void oo(string str, T val) {
    cerr << str << val << endl;
}

template<typename T = int>
inline T read() {
    T x;
    cin >> x;
    return x;
}

#define endl '\n'
#define FOR(i, x, y) \
  for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) \
  for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int M = read(), N = read();
    vector<int> primes{2, 3, 5, 7};
    for (int i = primes.back() + 2; i <= 1e6; i += 2) {
        bool flag = true;
        for (auto p : primes) {
            if (p * p > i) break;
            if (i % p == 0) {
                flag = false;
                break;
            }
        }
        if (flag) primes.emplace_back(i);
    }
    for (int i = M - 1; i < N; i++) {
        cout << primes[i];
        if ((i - M + 1) % 10 == 9)
            cout << endl;
        else if (i < N - 1)
            cout << " ";
    }

    return 0;
}
