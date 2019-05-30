#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


typedef long long LL;

//任意映射的打印方法 支持 map/multiMap vector<pair<>>等 方便调试
template<typename T>
void OOM(T a, string s = "") {
    cerr << s << ":\t";
    for (auto e:a) {
        cerr << e.first << "," << e.second << " ";
    }
    cerr << endl;
}

//任意容器的打印方法 支持 vector list set multiset等 方便调试
template<typename T>
void OO(T a, string s = "") {
    cerr << s << ":\t";
    for (auto e:a) {
        cerr << e << " ";
    }
    cerr << endl;
}

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
    iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s(read<string>());
    vector<int> a, b;
    FOR(i, 0, s.size() - 1) {
        if (s.substr(i, 2) == "AB")a.push_back(i);
        if (s.substr(i, 2) == "BA")b.push_back(i);
    }
    //OO(a, "a:");
    // OO(b, "b:");
    bool flag = false;
    FOR(x, 0, a.size()) {
        FOR(y, 0, b.size()) {
            if (abs(a[x] - b[y]) >= 2) {
                flag = true;
                break;
            }
        }
        if (flag)break;
    }

    cout << (flag ? "YES" : "NO") << endl;
    return 0;

}
