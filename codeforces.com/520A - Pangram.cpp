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
    read<int>();
    string s = read<string>();
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    set<char> S;
    for (auto c:s)S.insert(c);
    cout << (S.size() == 26 ? "YES" : "NO");

    return 0;
}
