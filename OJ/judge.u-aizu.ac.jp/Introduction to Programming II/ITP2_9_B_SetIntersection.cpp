#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  set<int> A;
  while (n--) {
    int t;
    cin >> t;
    A.insert(t);
  }
  int m;
  cin >> m;
  set<int> B;
  while (m--) {
    int t;
    cin >> t;
    if (A.find(t) != A.end()) {
      B.insert(t);
    }
  }
  for (auto x : B)
    cout << x << endl;
  return 0;
}