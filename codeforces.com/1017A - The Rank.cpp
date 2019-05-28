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
    vector<pair<int, int>> S(read<int>());
    FOR(i, 0, S.size()) {
        S[i].first = i + 1;
        S[i].second = read<int>() + read<int>() + read<int>() + read<int>();

    }
    pair<int, int> thomas = S[0];
    sort(S.begin(), S.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.second != b.second)return a.second > b.second;
        return a.first < b.first;
    });
    cout << find(S.begin(), S.end(), thomas) - S.begin() + 1 << endl;
    return 0;
}
