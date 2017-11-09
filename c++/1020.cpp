#include <bits/stdc++.h>
using namespace std;

bool cmp(const int &a, const int &b) { return a > b; }
int main() {
  vector<int> v(10);
  for (auto &p : v) cin >> p;
  sort(v.begin(), v.end(), cmp);
  for (auto p : v) cout << p << " ";
  cout << endl;
  return 0;
}
