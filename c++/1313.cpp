#include <bits/stdc++.h>
using namespace std;
bool ok(int n) {
  if (n % 7 == 0) return true;
  while (n) {
    if (n % 10 == 7) return true;
    n /= 10;
  }
  return false;
}
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  for (auto i = 1; i <= n; i++) {
    if (ok(i)) {
      cout << i << endl;
    }
  }
  return 0;
}