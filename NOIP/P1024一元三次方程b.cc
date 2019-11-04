#include <bits/stdc++.h>
using namespace std;

double a, b, c, d, ans[4];
int n;

inline double Equation(double x) { return ((a * x + b) * x + c) * x + d; }
inline void solve(double l, double r) {
  if (Equation(l) * Equation(r) > 0 && ((r - 1) < 1 || n >= 2)) return;
  double mid = (l + r) / 2;
  if (abs(Equation(mid)) <= 1e-4) {
    ans[++n] = mid;
    return;
  }
  solve(l, mid);
  solve(mid, r);
}

int main() {
  cin >> a >> b >> c >> d;
  solve(-100, 100);
  cout << fixed << setprecision(2) << ans[1] << ' ' << ans[2] << ' ' << ans[3]
       << '\n';
  return 0;
}