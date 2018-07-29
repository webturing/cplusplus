#include <bits/stdc++.h>
using namespace std;
double a, b, c, d;
inline double f(double x) { return a * x * x * x + b * x * x + c * x + d; }
int main(int argc, char const *argv[]) {
  cin >> a >> b >> c >> d;
  vector<double> roots;
  for (double x = -100; x <= 100; x += 0.01) {
    if (abs(f(x)) <= 1e-3) roots.push_back(x);
  }
  for (auto root : roots) cout << fixed << setprecision(2) << root << " ";
  cout << endl;
  return 0;
}