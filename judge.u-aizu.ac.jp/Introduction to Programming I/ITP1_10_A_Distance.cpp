#include <bits/stdc++.h>
using namespace std;

int main() {
  double x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  cout << fixed << setprecision(8) << hypot(x1 - x2, y1 - y2) << endl;
  return 0;
}