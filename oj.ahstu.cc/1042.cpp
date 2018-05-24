#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>
using namespace std;
int main() {
  int n;
  cin >> n;
  auto s = 1ull;
  for (int i = 2; i <= n; i++) s *= i;
  cout << s << endl;
  return 0;
}
