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
  map<pair<char, char>, int> G;
  map<int, int> H;
  map<char, int> X, Y;
  string s("CJB");
  FOR(x, 0, 3) FOR(y, 0, 3) {
    if (x == y) G[{s[x], s[y]}] = 0;
    if (y == (x + 1) % 3) G[{s[x], s[y]}] = 1;
    if (y == (x + 2) % 3) G[{s[x], s[y]}] = -1;
  }
  FOR(i, 0, read()) {
    string x, y;
    cin >> x >> y;
    H[G[{x[0], y[0]}]]++;
    if (G[{x[0], y[0]}] == 1) {
      X[x[0]]++;
    }
    if (G[{x[0], y[0]}] == -1) {
      Y[y[0]]++;
    }
  }
  cout << H[1] << " " << H[0] << ' ' << H[-1] << endl;
  cout << H[-1] << " " << H[0] << ' ' << H[1] << endl;
  char Cx = 'B', Cy = 'B';
  for (auto c : string("CJ")) {
    if (X[c] > X[Cx]) Cx = c;
    if (Y[c] > Y[Cy]) Cy = c;
  }
  cout << Cx << " " << Cy << endl;
  return 0;
}
