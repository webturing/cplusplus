#include <iostream>

using namespace std;

int main() {
  for (int n, a, b, c; cin >> n && n;) {
    a = n / 100;
    b = n / 10 % 10;
    c = n % 10;
    if (n == a * a * a + b * b * b + c * c * c)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}