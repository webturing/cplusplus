#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
  string s(read<string>());
  map<char, int> M;
  for (char c : s) M[c]++;
  for (auto p : M) cout << p.first << ":" << p.second << endl;
  return 0;
}
