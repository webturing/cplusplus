//
// Created by Administrator on 2019/6/1.
//

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

int my_hash(int x) {
    return x < 10 ? x : my_hash(x / 10) + x % 10;
}


struct my_cmp {
    bool operator()(int a, int b) const {
        return my_hash(a) < my_hash(b);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> v{4, 3, 6, 23, 87, 45, 543, 23, 5, 1000};


    priority_queue<int, vector<int>, my_cmp> Q;
    for (auto i : v) {
        Q.push(i);
    }
    while (not Q.empty()) {
        cout << Q.top() << " ";
        Q.pop();
    }
    return 0;
}

