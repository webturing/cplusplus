#include <iostream>
#include <iomanip>

using namespace std;
bool prime(int n) {
  if (n < 0) n = -n;
  if (n == 2) return true;
  if (n < 2 || n % 2 == 0) return false;
  for (int c = 3; c * c <= n; c += 2)
    if (n % c == 0) return false;
  return true;
}
bool sys(int n) {
  int m, cn = n;
  for (m = 0; n; n /= 10) m = 10 * m + n % 10;
  return m == cn;
}
int main(int argc, char const *argv[]) {
  int a, b;
  cin >> a >> b;
  for (int n = a; n <= b; n++)
    if (sys(n) && prime(n)) cout << n << endl;
  return 0;
}
