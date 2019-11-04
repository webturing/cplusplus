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
    vector<int> v(read<int>());
    FOR(i, 0, v.size())v[i] = read<int>();
    sort(v.begin(), v.end());
    for (auto i:v)cout << i << " ";
    cout << endl;
    return 0;

}
