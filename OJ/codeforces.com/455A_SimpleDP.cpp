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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int n(read<int>());
    vector<LL> v(n);
    map<LL, LL> M;
    FOR(i, 0, n) {
        v[i] = read<LL>();
        M[v[i]]++;
    }

    vector<LL> dp(*max_element(v.begin(), v.end()) + 1, 0);
    dp[0] = 0;
    FOR(i, 1, dp.size()) {
        dp[i] = 1LL * M[i] * i;
        if (i >= 2) {
            dp[i] += dp[i - 2];
        }
        if (dp[i] < dp[i - 1])dp[i] = dp[i - 1];
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;

    return 0;
}
