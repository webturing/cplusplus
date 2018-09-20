#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  bitset<64> b(0);
  while (q--) {
    int x;
    int op;
    cin >> op;
    switch (op) {
    case 0:
      cin >> x;
      cout << b.test(x) << endl;
      break;
    case 1:
      cin >> x;
      b.set(x);
      break;
    case 2:
      cin >> x;
      b.reset(x);
      break;
    case 3:
      cin >> x;
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