#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD = 1e9 + 7;
LL mpower(LL a, int n) {
  long long ans = 1;
  while (n > 0) {
    if (n & 1) {
      ans *= a;
      ans %= MOD;
    }
    a *= a % MOD;
    a %= MOD;
    n >>= 1;
  }
  return ans % MOD;
}
int main() {
  int n, m;
  cin >> m >> n;
  cout << mpower(m, n) << endl;

  return 0;
}