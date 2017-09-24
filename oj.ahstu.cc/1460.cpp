#include <bits/stdc++.h>
using namespace std;
#define ONLINE_JUDGE
const int MAX_LENGTH = 16;
void solve() {
  int test;
  int cas = 1;
  char str[MAX_LENGTH];
  for (cin >> test; test--; ++cas) {
    cin >> str;
    cout << "Case #" << cas << ": ";
    if (NULL == strstr(str, "13")) {
      cout << "Yes, I like it!" << endl;
    } else {
      cout << "No, it's terrible!" << endl;
    }
  }
  return;
}
int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
#endif
  solve();

  return EXIT_SUCCESS;
}