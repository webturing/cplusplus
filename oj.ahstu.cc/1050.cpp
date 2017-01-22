#include <iostream>
#include <vector>
using namespace std;
int main() {

  for (int n, m; cin >> n >> m;) {
    vector<int> v(1, 2);
    while (v.size() < n) v.push_back(v[v.size() - 1] + 2);
    // for (int i = 0; i < v.size(); ++i) cout << v[i] << endl;
    int start = m + 1;

    for (int j = 0; j < n / m; j++) cout << start + j* m * 2 << ' ';
    if (n % m == 0)
      cout << endl;
    else {
      int tot = 0;
      for (int i = n / m * m; i < n; i++) tot += 2 * (i + 1);
      cout << tot / (n % m) << endl;
    }
  }
  return 0;
}
