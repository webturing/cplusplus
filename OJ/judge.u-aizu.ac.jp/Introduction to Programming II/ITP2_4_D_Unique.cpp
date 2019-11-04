#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &p : a) cin >> p;
  auto p = unique(a.begin(), a.end());
  for (int i = 0; i < p - a.begin(); i++) {
    if (i) cout << " ";
    cout << a[i];
  }
  cout << endl;
  return 0;
}