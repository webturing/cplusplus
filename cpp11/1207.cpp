
#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>
using namespace std;
int main() {
  for (int n; cin >> n && n;) {
    auto a = n / 100, b = (n % 100) / 10, c = n % 10;
    if (n >= 100 && n <= 999 && a * a * a + b * b * b + c * c * c == n)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
