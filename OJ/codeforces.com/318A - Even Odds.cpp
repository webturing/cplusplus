#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long LL;

template<typename T>
inline void oo(string str, T val) { cerr << str << val << endl; }

template<typename T>
inline T read() {
    T x;
    cin >> x;
    return x;
}

#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)

int main() {
    LL n = read<LL>(), k = read<LL>();
    if (k <= (n + 1) / 2) {
        cout << 2 * k - 1 << endl;
    } else {
        k -= (n + 1) / 2;
        cout << 2 * k << endl;
    }
    return 0;
}
