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
  int n = read();
  while (true) {
    vector<int> v = {n / 1000, n % 1000 / 100, n % 100 / 10, n % 10};
    sort(v.begin(), v.end());
    int small = v[0] * 1000 + v[1] * 100 + v[2] * 10 + v[3];
    int big = v[3] * 1000 + v[2] * 100 + v[1] * 10 + v[0];

    if (small == big) {
      cout << setw(4) << setfill('0') << big << " - " << setw(4) << setfill('0')
           << small << " = "
           << "0000" << endl;
      break;
    }
    n = big - small;
    cout << setw(4) << setfill('0') << big << " - " << setw(4) << setfill('0')
         << small << " = " << setw(4) << setfill('0') << n << endl;
    if (n == 6174) break;
  }

  return 0;
}
