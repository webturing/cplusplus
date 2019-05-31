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
    freopen("input.txt", "r", stdin);
    for (;;) {
        int n(read<int>()), m(read<int>()), X(read<int>()), Y(read<int>());
        if (cin.fail())break;
        map<PII, int> G, V;
        FOR(i, 0, n)FOR(j, 0, m)G[make_pair(i, j)] = read<int>() > 0;
        int tot = 0, dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
        queue<PII> Q;
        Q.push(make_pair(X, Y));
        V[make_pair(X, Y)] = true;
        while (not Q.empty()) {
            PII p = Q.front();
            V[p] = true;
            int x0 = p.first, y0 = p.second;
            FOR(i, 0, 4) {
                int nx = x0 + dir[i][0];
                int ny = y0 + dir[i][1];
                PII q = make_pair(nx, ny);
                if (V[q] or G[q] == 0)continue;
                Q.push(q);
                V[q] = true;
            }
            if (G[p])++tot;
            // cerr<<p.first<<" "<<p.second<<endl;
            Q.pop();
        }
        cout << tot << endl;
    }
    return 0;
}

