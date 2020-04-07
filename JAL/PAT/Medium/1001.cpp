// 1001	害死人不偿命的(3n+1)猜想
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

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
  int n(read());
  int step(0);
  while (n > 1) {
    if (n & 1) {
      n = 3 * n + 1;
    } else {
      n /= 2;
      ++step;
    }
  }
  cout << step << endl;
    return 0;
}
