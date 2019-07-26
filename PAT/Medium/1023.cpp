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
  vector<int> v;
  for (int i = 0; i <= 9; i++) {
    int n;
    cin >> n;
    for (int j = 0; j < n; j++) v.emplace_back(i);
  }
  sort(v.begin(), v.end());
  if (v[0] == 0) {
    int i = 1;
    for (; i < v.size(); i++) {
      if (v[i] > 0) break;
    }
    swap(v[0], v[i]);
  }
  for (auto d : v) cout << d;
  cout << endl;
  return 0;
}
