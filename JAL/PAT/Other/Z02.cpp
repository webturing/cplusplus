#include <bits/stdc++.h>
using namespace std;
bool prime(int n) {
  if (n == 2) return true;
  if (n < 2 or n % 2 == 0) return false;
  for (int c = 3; c * c <= n; c += 2) {
    if (n % c == 0) return false;
  }
  return true;
}
int main() {
  int n;
  cin >> n;
  int tot(0);
  for (int i = 3; i + 2 <= n; i += 2) {
    if (prime(i) and prime(i + 2)) ++tot;
  }
  cout << tot << endl;
  return 0;
}