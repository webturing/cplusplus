#include <bits/stdc++.h>

using namespace std;

using LL = long long;

template<typename T = int>
inline void oo(string str, T val) {
    cerr << str << val << endl;
}

template<typename T = int>
inline T read() {
    T x;
    cin >> x;
    return x;
}

#define endl '\n'
#define FOR(i, x, y) \
  for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) \
  for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<LL> A1, A2, A3, A4, A5;
    FOR(i, 0, read()) {
        int x(read());
        if (x % 5 == 0 and x % 2 == 0) A1.emplace_back(x);
        if (x % 5 == 1) A2.emplace_back((A2.size() & 1) ? -x : x);
        if (x % 5 == 2) A3.emplace_back(1);
        if (x % 5 == 3) A4.emplace_back(x);
        if (x % 5 == 4) A5.emplace_back(x);
    }
    if (A1.empty())
        cout << "N";
    else
        cout << accumulate(A1.begin(), A1.end(), 0);
    cout << " ";
    if (A2.empty())
        cout << "N";
    else
        cout << accumulate(A2.begin(), A2.end(), 0);
    cout << " ";
    if (A3.empty())
        cout << "N";
    else
        cout << accumulate(A3.begin(), A3.end(), 0);
    cout << " ";
    if (A4.empty())
        cout << "N";
    else
        cout << fixed << setprecision(1)
             << accumulate(A4.begin(), A4.end(), 0.0) / A4.size();
    cout << " ";
    if (A5.empty())
        cout << "N";
    else
        cout << *max_element(A5.begin(), A5.end()) << endl;
    return 0;
}
