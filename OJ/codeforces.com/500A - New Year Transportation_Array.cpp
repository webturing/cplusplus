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
    int t = read<int>();
    int a[n + 1], v[n + 1];
    for (int i = 1; i < n; i++) {
        a[i] = read<int>();
        v[i] = false;
    }

    for (int start = 1;;) {
        start += a[start];
        if (start >= n)break;
        v[start] = true;
    }

    if (v[t]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
