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
    int left = lower_bound(a.begin(), a.end(), k) - a.begin();
    int right = upper_bound(a.begin(), a.end(), k) - a.begin();
    cout << left << " " << right << endl;
  }
  return 0;
}