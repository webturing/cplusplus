#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

using LL = long long;

template <typename T = int>
inline void oo(string str, T val) {
  cerr << str << val << endl;
}

template <typename T = int>
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

string R("0123456789abcdefghijklmnopqrstuvwxyz");
LL getval(string s, int r) {
  LL tot = 0;
  for (auto c : s) {
    int p = R.find(c);
    if (p >= r) return -1;
    tot = tot * r + p;
  }
  return tot;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string a, b;
  int x, y;
  cin >> a >> b >> x >> y;
  LL k = x == 1 ? getval(a, y);
  int rr = -1;
  for (int r = 2; r <= 36; r++) {
    if (k == getval(b, r)) {
      rr = r;
      break;
    }
  }
  if (rr == -1)
    cout << "Impossible" << endl;
  else
    cout << rr << endl;
  return 0;
}
