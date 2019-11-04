#include <bits/stdc++.h>
using namespace std;
int main() {
  ifstream cin("in.txt");
  int n, q;
  cin >> n >> q;
  vector<vector<int>> A(n);
  while (q--) {
    int op, t;
    cin >> op >> t;
    if (op == 0) {
      int x;
      cin >> x;
      A[t].push_back(x);
    } else if (op == 1) {
      for (int i = 0; i < A[t].size(); i++) {
        if (i) cout << " ";
        cout << A[t][i];
      }
      cout << endl;
    } else if (op == 2) {
      A[t].clear();
    }
  }

  return 0;
}