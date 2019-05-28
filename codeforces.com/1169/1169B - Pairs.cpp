#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long LL;

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
    int n(read<int>()), m(read<int>());
    set<pair<int, int>> E;

    FOR(i, 0, m) {
        int x(read<int>()), y(read<int>());
        if (x > y)swap(x, y);
        E.insert(make_pair(x, y));
    }
    m = E.size();
    map<int, int> G;
    for (auto e:E)G[e.first]++, G[e.second]++;

    FOR(i, 0, 2) {
        vector<pair<int, int>> P(G.begin(), G.end());
        sort(P.begin(), P.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.second > b.second;
        });
        for (auto it = E.begin(); it != E.end();)
            if (it->first == P[0].first or it->second == P[0].first) {
                G[it->first]--;
                G[it->second]--;
                E.erase(it++);
            } else
                ++it;
    }
    //for(auto e:E)cout<<e.first<<" "<<e.second<<endl;
    cout << (E.empty() ? "YES" : "NO") << endl;
    return 0;
}