
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
  double f;
  cin >> f;
  cout << setiosflags(ios::fixed) << setprecision(3) << 5 * (f - 32) / 9
       << endl;
  return 0;
}
