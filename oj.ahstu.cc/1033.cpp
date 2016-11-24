#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int n;
  cin >> n;
  cout << (int)((sqrt(8 * sqrt(n) + 1) - 1) / 2) << endl;
  return 0;
}
