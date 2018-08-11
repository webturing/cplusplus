#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream cin("B.txt");
  ios::sync_with_stdio(false);
  for (int n, q; cin >> n >> q;) {
    vector<list<int>> V(n + 1);
    while (q--) {
      int op;
      cin >> op;
      if (op == 1) {
        int u, w, val;
        cin >> u >> w >> val;
        if (w == 1)
          V[u].push_back(val);
        else
          V[u].push_front(val);
      } else if (op == 2) {
        int u, w;
        cin >> u >> w;
        if (V[u].empty())
          cout << -1 << endl;
        else {
          int ele;
          if (w == 1) {
            ele = V[u].back();
            V[u].pop_back();
          } else {
            ele = V[u].front();
            V[u].pop_front();
          }
          cout << ele << endl;
        }
      } else if (op == 3) {
        int u, v, w;
        cin >> u >> v >> w;
        if (w == 0) {
          V[u].merge(V[v]);
        } else {
          V[v].reverse();
          V[u].merge(V[v]);
        }
      }
    }
  }
  return 0;
}