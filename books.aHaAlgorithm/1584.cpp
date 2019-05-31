#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)

using LL=long long;
using VI=vector<int>;
using PII=pair<int, int>;

//任意映射的打印方法 支持 map/multiMap vector<pair<>>等 方便调试
template<typename T>
void OOM(T a, string s = "") {
    cerr << s << ":";
    for (auto e:a) {
        cerr << e.first << ":" << e.second << " ";
    }
    cerr << endl;
}

//任意容器的打印方法 支持 vector list set multiset等 方便调试
template<typename T>
void OO(T a, string s = "") {
    cerr << s << ":";
    for (auto e:a) {
        cerr << e << " ";
    }
    cerr << endl;
}

template<typename T>
inline void oo(T val, string str = "") { cerr << str << val << endl; }

template<typename T>
inline T read() {
    T x;
    cin >> x;
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (;;) {
        int n(read<int>()), m(read<int>());
        if (cin.fail())break;
        map<PII, char> G;
        FOR(i, 0, n)FOR(j, 0, m)G[make_pair(i, j)] = read<char>();
        int gmax = 0;
        for (auto p:G) {
            if (p.second == 'G' or p.second == '#')continue;
            int x0 = p.first.first, y0 = p.first.second;
            int tot = 0;
            FOR(x, x0 + 1, n) {
                if (G[make_pair(x, y0)] == '#')break;
                if (G[make_pair(x, y0)] == 'G')++tot;
            }
            FOR(y, y0 + 1, m) {
                if (G[make_pair(x0, y)] == '#')break;
                if (G[make_pair(x0, y)] == 'G')++tot;
            }
            FORD(x, x0 - 1, -1) {
                if (G[make_pair(x, y0)] == '#')break;
                if (G[make_pair(x, y0)] == 'G')++tot;
            }
            FORD(y, y0 - 1, -1) {
                if (G[make_pair(x0, y)] == '#')break;
                if (G[make_pair(x0, y)] == 'G')++tot;
            }
            gmax = max(tot, gmax);
        }
        cout << gmax << endl;
    }
    return 0;
}