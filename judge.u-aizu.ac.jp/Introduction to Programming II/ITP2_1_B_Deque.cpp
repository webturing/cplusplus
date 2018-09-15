#include <bits/stdc++.h>
using namespace std;
int main() {

  deque<int> a;
  int q;
  cin >> q;
  while (q--) {
    int op;
    cin >> op;
    if (op == 0) {
      int d, x;
      cin >> d >> x;
      if (d == 0)
        a.push_front(x);
      else
        a.push_back(x);
    } else if (op == 1) {
      int p;
      cin >> p;
      cout << a[p] << endl;
    } else {
      int d;
      cin >> d;
      if (d == 0)
        a.pop_front();
      else
        a.pop_back();
    }
  }

  return 0;
}