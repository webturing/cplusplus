#include <bits/stdc++.h>
using namespace std;

int main() {
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    if (n == 1) {
      cout << 5 << endl;
    } else
      cout << n + 5 << endl;
  }
  return 0;
}