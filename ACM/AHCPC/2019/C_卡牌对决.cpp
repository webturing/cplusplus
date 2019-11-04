#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define endl '\n'
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)

template<typename T>
void OOM(T a, string s = "") {
    cerr << s << ":";
    for (auto e:a) cerr << e.first << "," << e.second << " ";
    cerr << endl;
}

template<typename T>
void OO(T a, string s = "") {
    cerr << s << ":";
    for (auto e:a)cerr << e << " ";
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

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n(read<int>()), m = n * 2;
    vector<int> A, B;
    map<int, bool> M;
    FOR(i, 1, m + 1)M[i] = true;
    FOR(i, 0, n) {
        int x(read<int>());
        B.push_back(x);
        M[x] = false;
    }
    FOR(i, 1, m + 1)if (M[i])A.push_back(i);

    sort(B.begin(), B.begin() + n / 2);
    sort(B.begin() + n / 2, B.end());
    sort(A.begin(), A.end(), greater<int>());
    reverse(A.begin(), A.begin() + n / 2);
    reverse(A.begin() + n / 2, A.end());

    int win = 0;
    FOR(i, 0, n)if (i < n / 2 and A[i] > B[i] or i >= n / 2 and A[i] < B[i])++win;
    cout << win << endl;
    return 0;
}
