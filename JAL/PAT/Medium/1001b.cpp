#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ll x, step = 0;
  cin >> x;
  while (x > 1) {
    if (x & 1) {
      x = 3 * x + 1;
    } else {
      x >>= 1;
      ++step;
    }
  }
  cout << step << endl;
  return 0;
}
