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
    map<int, int> M;
    int last_odd = 1, last_even = 1;
    for (int i = 1; i <= n; i++) {
        int k = read<int>() & 1;
        M[k]++;
        if (k)last_even = i;
        else last_odd = i;
    }
    if (M[0] == 1)cout << last_odd;
    else cout << last_even;
    return 0;
}
