#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

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
    FOR(a, 123, 999) {
        if (a * 3 > 987) {
            break;
        }
        int b = 2 * a;
        int c = 3 * a;
        vector<int> d{a / 100, a % 100 / 10, a % 10, b / 100, b % 100 / 10, b % 10, c / 100, c % 100 / 10, c % 10};
        sort(d.begin(), d.end());
        vector<int> e{1, 2, 3, 4, 5, 6, 7, 8, 9};
        if (d == e) {
            cout << a << " " << b << " " << c << endl;
        }
    }

    return 0;
}
