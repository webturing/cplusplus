
#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>
using namespace std;
int main() {
  int m, n;
  cin >> m >> n;
  auto r = 15;
  m = (m + r - 1) / r * r;
  n = n / r * r;
  cout << (n - m) / r + 1 << endl;

  return 0;
}
