#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> &v, size_t i, int x) {
  if (x == 0)
    return true;
  if (i >= v.size())
    return false;
  return check(v, i + 1, x) || check(v, i + 1, x - v[i]);
}
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &e : v)
    cin >> e;
  sort(v.begin(), v.end());
  int q;
  cin >> q;
  while (q--) {

    int x;
    cin >> x;
    if (check(v, 0, x))
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
  return 0;
}
