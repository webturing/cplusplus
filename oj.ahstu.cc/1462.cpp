#include <bits/stdc++.h>
using namespace std;
#define ONLINE_JUDGE
void solve() {
  int test, n;
  int cas = 1;
  for (cin >> test; test--; ++cas) {
    cin >> n;
    cout << "Case #" << cas << ": " << endl;
    if (1 == n) {
      cout << "1" << endl << endl;
      continue;
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < 2 * (n - i); ++j) {
        cout << " ";
      }
      cout << "1";
      for (int j = 2; j <= i; ++j) {
        cout << " " << j;
      }
      for (int j = i - 1; j >= 1; --j) {
        cout << " " << j;
      }
      cout << endl;
    }
    for (int i = n - 1; i >= 1; --i) {
      for (int j = 0; j < 2 * (n - i); ++j) {
        cout << " ";
      }
      cout << "1";
      for (int j = 2; j <= i; ++j) {
        cout << " " << j;
      }
      for (int j = i - 1; j >= 1; --j) {
        cout << " " << j;
      }
      cout << endl;
    }
    cout << endl;
  }
  return;
}
int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
#endif
  solve();
  return EXIT_SUCCESS;
}