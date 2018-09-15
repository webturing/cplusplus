#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &p : a) cin >> p;
  int q;
  cin >> q;
  while (q--) {
    int b, e, t;
    cin >> b >> e >> t;
    for (int k = 0; k < e - b; k++) swap(a[b + k], a[t + k]);
  }
  for (int i = 0; i < n; i++) {
    if (i) cout << " ";
    cout << a[i];
  }
  cout << endl;
  return 0;
}