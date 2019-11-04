#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using piir = pair<int, int>;

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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  LL a = read<LL>(), b = read<LL>(), c = a + b;
  int d = read();
  if (c == 0) {
    cout << 0 << endl;
    return 0;
  }
  stack<int> S;
  while (c > 0) {
    S.push(c % d);
    c /= d;
  }
  while (not S.empty()) {
    cout << S.top();
    S.pop();
  }
  return 0;
}
