#include <bits/stdc++.h>
using namespace std;

using ll = __int128;

template <typename T = int>
inline void oo(string str, T val) {
  cerr << str << val << endl;
}

template <typename T = ll>
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
  FOR(i, 1, read() + 1) {
    cout << "Case #" << i << ": ";
    ll A(read<int>()), B(read()), C(read());
    if (A + B > C)
      cout << "true";
    else
      cout << "false";
    cout << endl;
  }
  return 0;
}
