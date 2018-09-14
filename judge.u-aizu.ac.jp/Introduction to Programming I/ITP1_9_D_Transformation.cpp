#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int q;
  cin >> q;
  while (q--) {
    string op;
    int a, b;
    cin >> op >> a >> b;
    if (op == "replace") {
      string p;
      cin >> p;
      string head(s.begin(), s.begin() + a);
      string tail(s.begin() + b + 1, s.end());
      s = head + p + tail;

    } else if (op == "reverse") {
      reverse(s.begin() + a, s.begin() + b + 1);
    } else if (op == "print") {
      copy(s.begin() + a, s.begin() + b + 1, ostream_iterator<char>(cout, ""));
      cout << endl;
    }
  }

  return 0;
}