#include <bits/stdc++.h>
using namespace std;
double a, b, c, d;
inline double f(double x) { return a * x * x * x + b * x * x + c * x + d; }
int main(int argc, char const *argv[]) {
  cin >> a >> b >> c >> d;
  for (double x = -100; x <= 100; x += 0.01) {
    if (abs(f(x)) <= 1e-3) cout << fixed << setprecision(2) << x << " ";
  }
  cout << endl;
  return 0;
}