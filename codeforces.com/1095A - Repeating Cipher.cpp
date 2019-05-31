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
    auto n = read<int>();
    string s(read<string>());
    for (int i = 1; i * (i + 1) / 2 - 1 < n; i++) {
        cout << (s[i * (i + 1) / 2 - 1]);
    }

    return 0;

}
