#include <bits/stdc++.h>

using namespace std;
#define LOCAL

int main() {
#ifdef LOCAL
  ifstream cin("input.txt");
  ofstream cout("output.txt");
  assert(cin);
#endif
  for (int n, m; cin >> n >> m;) {
    vector<int> v(n);
    for (auto i = 0; i < n; i++) v[i] = 1 + i;
    for (int i = -1; n > 1; n--) {
      for (int j = 0; j < m; j++) {
        do {
          i = (i + 1) % v.size();
        } while (v[i] == 0);
      }
      v[i] = 0;
    }
    cout << *max_element(v.begin(), v.end()) << endl;
  }
#ifdef LOCAL
  cin.close();
  cout.close();
#endif
  return 0;
}