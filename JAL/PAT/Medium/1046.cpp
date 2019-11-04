#include <bits/stdc++.h>
using namespace std;
int main() {
  // ifstream cin("input.txt");
  int a = 0, a1, a2, b(0), b1, b2;
  int T;
  cin >> T;
  while (T--) {
    cin >> a1 >> a2 >> b1 >> b2;
    cerr << a1 << " " << a2 << " " << b1 << " " << b2 << endl;
    bool aWin = (a2 == a1 + b1);
    bool bWin = (b2 == a1 + b1);
    cerr << aWin << " vs " << bWin << endl;
    if (aWin ^ bWin) {
      if (aWin) ++a;
      if (bWin) ++b;
    }
  }
  cout << b << " " << a << endl;
  return 0;
}