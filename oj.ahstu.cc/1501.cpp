#include <iostream>
using namespace std;
int f(int a, int p, int m) {
  a %= m;
  if (p == 1 || a == 0) return a % m;
  if (a == 1) return 1;
  if (p % 2 == 0) return f(a * a % m, p / 2, m);
  return (f(a * a % m, p / 2, m) * a) % m;
}
int main() {

  for (int a, b, c; cin >> a >> b >> c, a + b + c; cout << f(a, b, c) << endl)
    ;
  return 0;
}