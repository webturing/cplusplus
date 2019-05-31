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
    map<int, int> M;
    FOR(i, 0, read<int>())M[read<int>()]++;
    int gmax = 0;
    for (auto p:M)gmax = max(p.second, gmax);
    cout << gmax << endl;
    return 0;
}
