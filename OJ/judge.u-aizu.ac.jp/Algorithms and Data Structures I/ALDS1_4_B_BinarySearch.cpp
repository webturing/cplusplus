#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &e : v)
    cin >> e;
  sort(v.begin(), v.end());
  int t;
  cin >> t;
  int cnt = 0;
  while (t--) {
    int x;
    cin >> x;
    if (binary_search(v.begin(), v.end(), x))
      ++cnt;
  }
  cout << cnt << endl;
  return 0;
}
