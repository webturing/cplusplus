#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef unsigned long long LL;

template<typename T>
void OOM(T a, string s = "") {
    cerr << s << ":";
    for (auto e:a) {
        cerr << e.first << "," << e.second << " ";
    }
    cerr << endl;
}

template<typename T>
void OO(T a, string s = "") {
    cerr << s << ":";
    for (auto e:a) {
        cerr << e << " ";
    }
    cerr << endl;
}

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


//#define LOCAL

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifdef LOCAL
    LL start = clock();
    //freopen("input.txt", "r", stdin);
#endif
    int n(read<int>()), m(read<int>()), a(read<int>()), b(read<int>());
    int c1 = a * n;
    int c2 = b * (n / m) + a * (n % m);
    int c3 = b * ((n + m - 1) / m);
    cout << min(c1, min(c2, c3)) << endl;

#ifdef LOCAL
    LL end = clock();
    cerr << fixed << setprecision(3) << (end - start) / CLOCKS_PER_SEC << " second(s)." << endl;
#endif
    return 0;
}
