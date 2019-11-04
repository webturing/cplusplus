#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
typedef long long LL;
const int MOD = 1e9 + 7;
#define LOCAL
int main() {
#ifdef LOCAL
  ifstream cin("J.in");
  assert(cin);
  ofstream cout("J.out");
  LL start = clock();
#endif
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int A, B, C, D, P, n;
    cin >> A >> B >> C >> D >> P >> n;
    vector<int> F(n + 1);
    F[1] = A;
    F[2] = B;
    for (int i = 3; i <= n; i++)
      F[i] = (F[i - 2] * C + F[i - 1] * D + (P + i - 1) / i) % MOD;
    cout << F[n] << endl;
  }
#ifdef LOCAL
  LL end = clock();
  cerr << fixed << setprecision(2) << 1.0 * (end - start) / CLOCKS_PER_SEC
       << " second(s)." << endl;
#endif
  return 0;
}
