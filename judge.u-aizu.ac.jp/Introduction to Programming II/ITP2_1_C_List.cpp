#include <bits/stdc++.h>
using namespace std;
int main() {
  ifstream cin("in.txt");
  list<int> L;
  list<int>::iterator p = L.begin();
  int q;
  cin >> q;
  while (q--) {
    int op;
    cin >> op;
    if (op == 0) {
      int x;
      cin >> x;
      p = L.insert(p, x);
    } else if (op == 1) {
      int d;
      cin >> d;
      if (d > 0)
        while (d--) {
          ++p;
        }
      else if (d < 0) {
        while (d++) {
          --p;
        }
      }

    } else {
      p = L.erase(p);
    }
  }
  for (list<int>::iterator p = L.begin(); p != L.end(); ++p) cout << *p << endl;

  return 0;
}