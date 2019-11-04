#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
LL lcm(LL a, LL b) { return a / gcd(a, b) * b; }
int main() {
  int n;
  cin >> n;
  int ans = 1;
  while (n--) {
    int t;
    cin >> t;
    ans = lcm(ans, t);
  }
  cout << ans << endl;

  return 0;
}