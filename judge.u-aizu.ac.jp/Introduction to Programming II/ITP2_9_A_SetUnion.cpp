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
  while (m--) {
    int t;
    cin >> t;
    A.insert(t);
  }
  for (auto x : A)
    cout << x << endl;
  return 0;
}