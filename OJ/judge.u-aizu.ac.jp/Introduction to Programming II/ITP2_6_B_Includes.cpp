#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& p : a) cin >> p;
  int m;
  cin >> m;
  vector<int> b(m);
  for (auto& p : b) cin >> p;
  cout << includes(a.begin(), a.end(), b.begin(), b.end()) << endl;
  return 0;
}