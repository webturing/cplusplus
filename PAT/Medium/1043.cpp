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
  string S("PATest"), T(read<string>());
  map<char, int> M;
  for (auto c : T) {
    if (S.find(c) == string::npos) continue;
    M[c]++;
  }

  while (true) {
    bool stop = true;
    for (auto c : S) {
      if (M[c] > 0) {
        cout << c;
        --M[c];
        stop = false;
      }
    }
    if (stop) break;
  }
  cout << endl;
  return 0;
}
