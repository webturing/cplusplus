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
    int n(read<int>());
    queue<int> Q;
    FOR(i, 0, n)Q.push(read<int>());
    while (not Q.empty()) {
        cout << Q.front() << " ";
        Q.pop();
        if (Q.empty())break;
        Q.push(Q.front());
        Q.pop();
    }
    cout << endl;
    return 0;
}


/**************************************************************
    Problem: 1582
    User: CXX11
    Language: C++
    Result: 正确
    Time:14 ms
    Memory:2576 kb
****************************************************************/