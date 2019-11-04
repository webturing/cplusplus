#include <bits/stdc++.h>
using namespace std;
int main() {

  vector<int> a;
  int q;
  cin >> q;
  while (q--) {
    int op;
    cin >> op;
    if (op == 0) {
      int x;
      cin >> x;
      a.push_back(x);
    } else if (op == 1) {
      int p;
      cin >> p;
      cout << a[p] << endl;
    } else {
      a.pop_back();
    }
  }

  return 0;
}