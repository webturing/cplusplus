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
    int n = read<int>();
    cout << n / 2 << endl;
    FOR(i, 1, n / 2)cout << 2 << " ";
    if (n & 1)cout << 3 << endl;
    else cout << 2 << endl;

    return 0;
}
