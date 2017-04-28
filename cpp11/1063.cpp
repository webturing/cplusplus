
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
  double x1, y1, x2, y2;
  while (cin >> x1 >> y1 >> x2 >> y2)
    cout << setiosflags(ios::fixed) << setprecision(2)
         << hypot(x1 - x2, y1 - y2) << endl;
  return 0;
}
