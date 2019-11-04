#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int extended_euclid(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int gcd = extended_euclid(b, a % b, x, y);
  int t = x;
  x = y;
  y = t - (a / b) * y;
  return gcd;
}

int main() {
  int a, b;
  cin >> a >> b;
  int x, y;
  extended_euclid(a, b, x, y);
  cout << x << " " << y << endl;
  return 0;
}