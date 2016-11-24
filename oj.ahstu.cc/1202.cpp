#include <iostream>

using namespace std;

bool ok(int n) {
  int m = n, s = 0;
  for (; n; n /= 10) s += n % 10;
  return m % s == 0;
}

int main() {
  for (int n; cin >> n;) cout << (ok(n) ? "Lucky Word" : "No Answer") << endl;
  return 0;
}