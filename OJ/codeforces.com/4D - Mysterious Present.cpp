#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;


typedef long long LL;

template<typename T>
void OOM(T a, string s = "") {
    cerr << s << ":\t";
    for (auto e:a) {
        cerr << e.first << "," << e.second << " ";
    }
    cerr << endl;
}

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

#define endl '\n'
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)

vector<pair<int, int>> getMaxSub(vector<pair<int, int>> v) {
    int size = v.size();
    vector<int> len(size, 1);
    vector<int> pos(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < i; ++j) {
            if (v[j].first < v[i].first and v[j].second < v[i].second && len[i] < len[j] + 1) {
                len[i] = len[j] + 1;
                pos[i] = j;
            }
        }
    }

    int max = -1;
    int lastPos = -1;
    for (int i = 0; i < len.size(); ++i) {
        if (max < len[i]) {
            max = len[i];
            lastPos = i;
        }
    }

    vector<pair<int, int>> res;
    for (int i = 0; i < max; ++i) {
        res.push_back(v[lastPos]);
        lastPos = pos[lastPos];
    }
    reverse(res.begin(), res.end());

    return res;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n(read<int>()), w(read<int>()), h(read<int>());

    map<pair<int, int>, int> M;
    vector<pair<int, int>> a;
    FOR(i, 0, n) {
        int ww(read<int>()), hh(read<int>());
        if (ww > w and hh > h) a.push_back(make_pair(ww, hh));
        M[make_pair(ww, hh)] = i + 1;
    }
    if (a.empty()) {
        cout << 0 << endl;
        return 0;
    }
    sort(a.begin(), a.end(), [](pair<int, int> pa, pair<int, int> pb) -> bool {
        if (pa.first != pb.first)return pa.first < pb.first;
        return pa.second < pb.second;
    });
    auto ans = getMaxSub(a);
    cout << ans.size() << endl;
    for (auto p:ans)cout << M[p] << " ";

    return 0;
}
