#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& p : a) cin >> p;
  int q;
  cin >> q;
  while (q--) {
    int k;
    cin >> k;
    cout << lower_bound(a.begin(), a.end(), k) - a.begin() << endl;
  }
  return 0;
}