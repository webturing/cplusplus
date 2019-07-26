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
struct S {
  string i;
  int d;
  int c;
  bool operator<(const S &that) const {
    if (d + c != that.d + that.c) return d + c > that.d + that.c;
    if (d != that.d) return d > that.d;
    return i < that.i;
  }
};
int main() {
  freopen("input.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N(read()), L(read()), H(read());
  vector<S> A, B, C, D;
  FOR(i, 0, N) {
    S s;
    cin >> s.i >> s.d >> s.c;
    if (s.d >= H and s.c >= H) {
      A.emplace_back(s);
    } else if (s.d >= H and s.c >= L) {
      B.emplace_back(s);
    } else if (s.d >= L and s.c >= L and s.d >= s.c) {
      C.emplace_back(s);
    } else if (s.d >= L and s.c >= L) {
      D.emplace_back(s);
    }
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());
  sort(D.begin(), D.end());
  cout << A.size() + B.size() + C.size() + D.size() << endl;
  for (auto s : A) cout << s.i << " " << s.d << " " << s.c << endl;
  for (auto s : B) cout << s.i << " " << s.d << " " << s.c << endl;
  for (auto s : C) cout << s.i << " " << s.d << " " << s.c << endl;
  for (auto s : D) cout << s.i << " " << s.d << " " << s.c << endl;
  return 0;
}
