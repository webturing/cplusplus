#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long LL;

template<typename T>
inline void oo(string str, T val) { cerr << str << val << endl; }

inline int read_int() {
    int x;
    scanf("%d", &x);
    return x;
}

#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)

int main() {
    LL k, l;
    cin >> k >> l;
    LL s = k;
    int tot = 0;
    while (s < l) {
        s *= k;
        ++tot;
    }
    if (s == l) cout << "YES" << endl << tot << endl;
    else cout << "NO" << endl;
    return 0;
}
