// 1002 写出这个数 (20 point(s))
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template<typename T = int>
inline void oo(string str, T val) {
    cerr << str << val << endl;
}

template<typename T = ll>
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
const string PAT("patPAT ");

bool check(string s) {
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    for (auto c : s) {
        if (PAT.find(c) == string::npos) return false;
    }
    int p = count(s.begin(), s.end(), 'P');
    int t = count(s.begin(), s.end(), 'T');
    if (p != 1 or t != 1) return false;
    int ip = s.find('P');
    s = s.substr(ip);
    int it = s.find('T');
    if (ip > it) return false;
    s = s.substr(ip, it);
    cerr << "s=" << s << endl;
    if (s.find('A') == string::npos) return false;
    return s.substr(it).size() <= 1;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    getline(cin, s);
    int T;
    istringstream iss(s);
    for (iss >> T; T-- and getline(cin, s);) {
        cout << (check(s) ? "YES" : "NO") << endl;
    }

    return 0;
}
