#include <bits/stdc++.h>
using namespace std;

int main() {
  for (int m; cin >> m;) {
    vector<int> v(1, 1);
    for (int i = 2, cs = 0; i <= m; i++) {
      for (auto &p : v) {
        cs += p * i;
        p = cs % 10;
        cs /= 10;
      }
      for (; cs > 0; cs /= 10) {
        v.push_back(cs % 10);
      }
    }
    for (auto p = v.rbegin(); p != v.rend(); ++p) {
      cout << *p;
    }
    cout << endl;
  }

  return 0;
}