// 1002 写出这个数 (20 point(s))
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
vector<string> D{"ling", "yi",  "er", "san", "si",
                 "wu",   "liu", "qi", "ba",  "jiu"};
int main() {
  std::iostream::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string s(read<string>());
  int t = accumulate(s.begin(), s.end(), 0) - s.length() * '0';
  ostringstream oss, oss1;
  oss << t;
  for (auto c : oss.str()) {
    oss1 << " " << D[c - '0'];
  }
  cout << oss1.str().substr(1) << endl;
  return 0;
}
