#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  double r;
  const double PI = atan(1.0) * 4;
  for (cin >> n; cin >> r, n--;)
    cout << setiosflags(ios::fixed) << setprecision(6) << PI * r * r << endl;
  return 0;
}
