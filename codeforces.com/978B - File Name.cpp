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
    read<int>();
    string s(read<string>());
    string t;
    int tot = 0;
    for (auto c:s) {
        if (c == 'x' and t.size() >= 2 and t.substr(t.size() - 2) == "xx") {
            ++tot;
            continue;
        }
        t.push_back(c);
    }
    cout << tot << endl;
    return 0;
}
