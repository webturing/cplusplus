
#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n % 2 == 0) --n;
  n = (n + 1) >> 1;
  cout << n* n << endl;
  return 0;
}
