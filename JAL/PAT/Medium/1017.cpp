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
    string s = read<string>();
    int d(read());
    vector<int> q;
    int cs = 0;
    for (auto c:s) {
        int a = (cs * 10 + c - '0');
        q.push_back(a / d);
        cs = a % d;
    }
    auto beg = q.begin();
    while (*beg == 0 && q.size() > 1) {
        q.erase(q.begin());
    }
    copy(q.begin(), q.end(), ostream_iterator<int>(cout, ""));
    cout << " " << cs << endl;


    return 0;
}
