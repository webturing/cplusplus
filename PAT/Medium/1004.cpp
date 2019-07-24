#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

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
struct Student {
  string name;
  string course;
  int score;
  Student(string name = "", string course = "", int score = 0)
      : name(name), course(course), score(score) {}
  Student(const Student& s) : name(s.name), course(s.course), score(s.score) {}
  bool operator<(const Student& that) const { return score > that.score; }
  friend istream& operator>>(istream& is, Student& s) {
    is >> s.name >> s.course >> s.score;
    return is;
  }
};
int main() {
  std::iostream::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  vector<Student> S(read());
  for (auto& s : S) cin >> s;
  sort(S.begin(), S.end());
  cout << S.front().name << " " << S.front().course << endl;
  cout << S.back().name << " " << S.back().course << endl;
  return 0;
}
