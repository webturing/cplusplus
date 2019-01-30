#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<bitset<64> > b(n);

  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    while (k--) {
      int x;
      cin >> x;
      b[i].set(x);
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int x;
    int op;
    cin >> op >> x;

    switch (op) {
    case 0:
      cout << b.test(x) << endl;
      break;
    case 1:
      b.set(x);
      break;
    case 2:
      b.reset(x);
      break;
    case 3:
      b.flip(x);
      break;
    case 4:
      cout << b.all() << endl;
      break;
    case 5:
      cout << b.any() << endl;
      break;
    case 6:
      cout << b.none() << endl;
      break;
    case 7:
      cout << b.count() << endl;
      break;
    case 8:
      cout << b.to_ulong() << endl;
      break;
    }
  }
  return 0;
}