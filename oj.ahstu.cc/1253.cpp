#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
int foo(long long n) {
  if (n == 1) return 1;
  if (n % 2)
    n = 3 * n + 1;
  else
    n /= 2;
  return foo(n) + 1;
}
int main() {
  ifstream cin("d:\\data\\1253\\sample.in");
  // ofstream cout("d:\\data\\1125\\sample.out");
  for (int a, b; cin >> a >> b;) {
    int left = min(a, b), right = max(a, b), mx = 0;
    for (int n = left; n <= right; n++) {
      int cur = foo(n);
      if (cur > mx) mx = cur;
    }
    cout << a << " " << b << " " << mx << endl;
  }
  return 0;
}