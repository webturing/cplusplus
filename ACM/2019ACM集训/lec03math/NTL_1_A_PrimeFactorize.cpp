#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  cout << n << ":";
  for (int i = 2; n > 1; i++) {
    if (i * i > n) break;
    while (n % i == 0) {
      cout << " " << i;
      n /= i;
    }
  }
  if (n > 1) cout << " " << n;
  cout << endl;
  return 0;
}