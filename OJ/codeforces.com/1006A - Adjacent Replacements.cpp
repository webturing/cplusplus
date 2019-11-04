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
    auto n(read<int>());
    vector<int> a(n, 0);
    FOR(i, 0, n)a[i] = read<int>();
    for (auto &e:a) {
        if ((e & 1) == 0)
            --e;
    }
    for (auto e:a)cout << e << " ";
    cout << endl;
    return 0;
}
