#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  while (cin >> s) {
    if (s == "-") break;
    int T;
    cin >> T;
    while (T--) {
      int x;
      cin >> x;
      string a(s.begin(), s.begin() + x);
      string b(s.begin() + x, s.end());
      s = b + a;
    }
    cout << s << endl;
  }

  return 0;
}