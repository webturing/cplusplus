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
    int com, b, e;
    cin >> com >> b >> e;
    if (com == 0) {
      cout << *min_element(A.begin() + b, A.begin() + e) << endl;
    } else if (com == 1) {
      cout << *max_element(A.begin() + b, A.begin() + e) << endl;
    }
  }
  return 0;
}