
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

template<typename T=int>
inline void oo(string str, T val) { cerr << str << val << endl; }

template<typename T=int>
inline T read() {
    T x;
    cin >> x;
    return x;
}

#define endl '\n'
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a, da, b, db;
    cin >> a >> da >> b >> db;
    int pa = 0, pb = 0;
    do {
        if (a % 10 == da) {
            pa = pa * 10 + da;
        }
        a /= 10;
    } while (a);
    do {
        if (b % 10 == db) {
            pb = pb * 10 + db;
        }
        b /= 10;
    } while (b);
    cout << pa + pb << endl;

    return 0;
}
