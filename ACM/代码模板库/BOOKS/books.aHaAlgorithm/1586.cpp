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

int n(read<int>());

vector<int> a(n), v(n, false);

void dfs(int k) {
    if (k == n) {
        copy(a.begin(), a.end(), ostream_iterator<int>(cout, ""));
        cout << endl;
        return;
    }
    FOR(i, 0, n) {
        if (v[i])continue;
        a[k] = i + 1;
        v[i] = true;
        dfs(k + 1);
        v[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    dfs(0);
    return 0;
}


/**************************************************************
    Problem: 1586
    User: CXX11
    Language: C++
    Result: 正确
    Time:21 ms
    Memory:2180 kb
****************************************************************/
