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
    int b, e;
    cin >> b >> e;
    reverse(a.begin() + b, a.begin() + e);
  }
  for (int i = 0; i < n; i++) {
    if (i) cout << " ";
    cout << a[i];
  }
  cout << endl;
  return 0;
}