#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

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
    stack<int> S;
    int tot = 0;
    vector<int> ans;
    FOR(i, 0, read<int>()) {
        auto x = read<int>();
        if (not S.empty() and S.top() >= x) {
            ans.push_back(S.size());
            tot++;
            while (not S.empty())S.pop();
        }
        S.push(x);
    }
    if (S.size()) {
        ans.push_back(S.size());
        ++tot;
    }
    cout << tot << endl;
    for (auto a:ans)cout << a << " ";
    cout << endl;

    return 0;
}
