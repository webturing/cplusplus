#include <bits/stdc++.h>
using namespace std;
int main() {
  set<int> S;
  int q;
  cin >> q;
  while (q--) {
    int op, x;
    cin >> op >> x;
    if (op == 0) {
      S.insert(x);
      cout << S.size() << endl;
    } else if (op == 1) {
      cout << (S.find(x) != S.end()) << endl;
    }
  }

  return 0;
}