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
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s(read<string>()), T("([{");
    stack<char> S;
    bool flag = true;
    for (auto c:s) {
        if (not flag)break;
        if (T.find(c) != string::npos) {
            S.push(c);
        }
        switch (c) {
            case ')':
                if (S.empty() or S.top() != '(')
                    flag = false;
                else S.pop();
                break;
            case ']':
                if (S.empty() or S.top() != '[')
                    flag = false;
                else S.pop();
                break;
            case '}':
                if (S.empty() or S.top() != '{')
                    flag = false;
                else S.pop();
                break;
        }

    }
    cout << (flag and S.empty() ? "YES" : "NO") << endl;

    return 0;
}