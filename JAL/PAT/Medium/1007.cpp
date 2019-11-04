#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

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
#define FOR(i, x, y)                                                           \
  for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y)                                                          \
  for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N(read());
    vector<int> primes{2, 3, 5, 7};
    for (int i = primes.back() + 2; i <= N; i += 2) {
        bool flag = true;
        for (auto p : primes) {
            if (p * p > i)
                break;
            if (i % p == 0) {
                flag = false;
                break;
            }
        }
        if (flag)
            primes.emplace_back(i);
    }
    int tot = 0;
    for (int i = 2; primes[i] <= N and i < primes.size(); i++) {
        if (primes[i] - primes[i - 1] == 2)
            ++tot;
    }
    cout << tot << endl;
    return 0;
}
