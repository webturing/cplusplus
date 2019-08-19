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
LL next(int n) {
  if (n == 1) return -1;
  if (n % 2 == 0) return n / 2;
  return (3 * n + 1) / 2;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  set<int, greater<int>> V;  // vertexs
  FOR(i, 0, read()) V.insert(read());

  map<int, set<int>> G;  // adj table
  for (auto v : V) {
    int n = v;
    G[v].insert(1);
    while (n != 1) {
      n = next(n);
      if (V.find(n) != V.end()) G[v].insert(n);
    }
  }
  map<int, int> D;  // degree
  for (auto v : V) {
    for (auto n : G[v]) D[n]++;
  }
  int j = 0;
  for (auto v : V) {
    if (D[v] == 0) {
      if (j++) cout << " ";
      cout << v;
    }
  }
  return 0;
}
