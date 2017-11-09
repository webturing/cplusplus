#include <bits/stdc++.h>
using namespace std;

const double PI = atan(1.0) * 4.0;
int main(int argc, char const *argv[]) {
  double r, h;
  double area;
  cin >> r >> h;
  area = 2 * PI * r * r + 2 * PI * r * h;
  cout << "Area=" << setiosflags(ios::fixed) << setprecision(3) << area << endl;
  return 0;
}