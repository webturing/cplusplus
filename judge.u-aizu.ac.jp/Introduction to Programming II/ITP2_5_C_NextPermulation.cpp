#include <bits/stdc++.h>
using namespace std;
void print(vector<int> v) {
  for (size_t i = 0; i < v.size(); i++) {
    if (i) cout << " ";
    cout << v[i];
  }
  cout << endl;
}
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &p : a) cin >> p;
  vector<int> b(a), c(a);
  prev_permutation(b.begin(), b.end());
  next_permutation(c.begin(), c.end());
  if (b < a) print(b);
  print(a);
  if (c > a) print(c);
  return 0;
}