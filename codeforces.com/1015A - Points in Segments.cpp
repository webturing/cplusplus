#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

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
    int n(read<int>()), m(read<int>());
    map<int, int> M;
    FOR(i, 0, n) {
        int l(read<int>()), r(read<int>());
        FOR(j, l, r + 1)M[j] = 1;
    }
    cout << m - M.size() << endl;
    FOR(i, 1, m + 1)if (M[i] == 0)cout << i << " ";
    cout << endl;
    return 0;
}
