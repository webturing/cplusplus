#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream cin("test.in");
  int m, f, r;
  while (cin >> m >> f >> r) {
    if (m == -1 && f == -1 && r == -1)
      break;
    if (m == -1 || f == -1) {
      cout << "F" << endl;
      continue;
    }
    int t = m + f;
    if (t >= 80) {
      cout << "A" << endl;
      continue;
    }
    if (t >= 65) {
      cout << "B" << endl;
      continue;
    }
    if (t >= 50) {
      cout << "C" << endl;
      continue;
    }
    if (t >= 30) {
      if (r >= 50)
        cout << "C" << endl;
      else
        cout << "D" << endl;
      continue;
    }
    cout << "F" << endl;
  }
  return 0;
}