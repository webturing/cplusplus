#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAX_SIZE = 20;
void solve() {
  int test, n, k;
  LL dp[MAX_SIZE][MAX_SIZE];
  int cas = 1;
  for (int i = 0; i < MAX_SIZE; ++i) {
    dp[i][1] = 1;
    dp[i][i] = 1;
  }
  for (int i = 3; i < MAX_SIZE; ++i) {
    for (int j = 2; j < i; ++j) {
      dp[i][j] = j * dp[i - 1][j] + dp[i - 1][j - 1];
    }
  }
  for (cin >> test; test--; ++cas) {
    cin >> n >> k;
    cout << "Case #" << cas << ": ";
    if (k > n) {
      cout << 0 << endl;
    } else {
      cout << dp[n][k] << endl;
    }
  }
  return;
}
int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);
#endif
  solve();
  return EXIT_SUCCESS;
}