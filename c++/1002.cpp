#include <bits/stdc++.h>
using namespace std;
void root2(double a, double b, double c, double &x1, double &x2) {
  double delta = b * b - 4 * a * c;
  x1 = (-b + sqrt(delta)) / (2 * a);
  x2 = (-b - sqrt(delta)) / (2 * a);
  if (x1 < x2) swap(x1, x2);
}
int main(int argc, char const *argv[]) {
  double a, b, c;
  double x1, x2;
  cin >> a >> b >> c;
  root2(a, b, c, x1, x2);
  cout << setiosflags(ios::fixed) << setprecision(2) << x1 << " " << x2 << endl;
  return 0;
}