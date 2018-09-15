#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) cin >> A[i];
  int q;
  cin >> q;
  while (q--) {
    int b, e, k;
    cin >> b >> e >> k;
    cout << count(A.begin() + b, A.begin() + e, k) << endl;
  }
  return 0;
}