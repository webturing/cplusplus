#include <bits/stdc++.h>
using namespace std;
int main() {
  ifstream cin("input.txt");
  ios::sync_with_stdio(false);
  for (int n; cin >> n;) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    bool flag = false;
    for (int i = n - 1; i >= 2; i--) {
      if (a[i - 1] + a[i - 2] > a[i]) {
        cout << a[i] + a[i - 1] + a[i - 2] << endl;
        flag = true;
        break;
      }
    }
    if (!flag) cout << -1 << endl;
  }
  return 0;
}