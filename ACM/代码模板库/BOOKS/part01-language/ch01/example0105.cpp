#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
int main(int argc, char const *argv[]) {
  double r, h, s1, s2, s;
  cin >> r >> h;
  s1 = PI * r * r;
  s2 = 2 * PI * r * h;
  s = s1 * 2 + s2;
  cout << "Area = " << fixed << setprecision(3) << s << endl;
  return 0;
}