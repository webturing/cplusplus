#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
  for (int n, m; cin >> n >> m;) {
    if (n == 0 && m == 0) break;
    vector<int> v(n + 1);
    v[n] = m;
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    cout << v[0];
    for (int i = 1; i <= n; i++) cout << " " << v[i];
    cout << endl;
  }
  return 0;
}
