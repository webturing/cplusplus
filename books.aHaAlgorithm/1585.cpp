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

    int n(read<int>()), m(read<int>()), X(read<int>()), Y(read<int>());
    PII f(X, Y);
    map<PII, char> G, V;
    FOR(i, 0, n)FOR(j, 0, m)G[make_pair(i, j)] = read<char>();

    int gmax = 0, dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
    queue<PII> Q;
    Q.push(f);
    V[f] = true;
    while (not Q.empty()) {
        PII p = Q.front();
        V[p] = true;
        int x0 = p.first, y0 = p.second;
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
        FOR(i, 0, 4) {
            int nx = x0 + dir[i][0];
            int ny = y0 + dir[i][1];
            PII q = make_pair(nx, ny);
            if (V[q] || G[q] != '.')continue;

            Q.push(q);
            V[q] = true;

        }
        cerr << Q.front().first << " " << Q.front().second << endl;
        Q.pop();
    }
    cout << gmax << endl;

    return 0;
}


/**************************************************************
    Problem: 1585
    User: CXX11
    Language: C++
    Result: 正确
    Time:3 ms
    Memory:2184 kb
****************************************************************/