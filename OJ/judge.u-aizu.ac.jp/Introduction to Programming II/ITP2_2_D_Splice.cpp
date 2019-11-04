#include <bits/stdc++.h>
using namespace std;
int main() {
  ifstream cin("in.txt");
  ios::sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<list<int>> L(n);
  while (q--) {
    int op;
    cin >> op;
    if (op == 0) {
      int t, x;
      cin >> t >> x;
      L[t].push_back(x);
    } else if (op == 1) {
      int t;
      cin >> t;
      bool first = true;
      for (auto p : L[t]) {
        if (first) {
          first = false;
        } else {
          cout << " ";
        }
        cout << p;
      }
      cout << endl;
    } else if (op == 2) {
      int s, t;
      cin >> s >> t;
      L[t].splice(L[t].end(), L[s]);
    }
  }

  return 0;
}