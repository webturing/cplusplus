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
    string s[n];
    FOR(i, 0, n)s[i] = read<string>();
    bool flag = false;
    FOR(i, 0, n) {
        if (s[i][0] == 'O' and s[i][1] == 'O') {
            s[i][0] = s[i][1] = '+';
            flag = true;
            break;
        }
        if (s[i][3] == 'O' and s[i][4] == 'O') {
            s[i][3] = s[i][4] = '+';
            flag = true;
            break;
        }
    }
    if (not flag)cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        FOR(i, 0, n)cout << s[i] << endl;
    }

    return 0;
}
