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
    auto n = read<int>();
    auto s = read<string>();
    auto a = count(s.begin(), s.end(), 'A');
    auto b = n - a;
    if (a > b)cout << "Anton";
    else if (a < b)cout << "Danik";
    else cout << "Friendship";

    return 0;
}
