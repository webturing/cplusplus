#include <iostream>
#include <map>
using namespace std;
int main() {
  for (int n, m, k, t; cin >> n >> m;) {
    map<int, bool> mp;
    for (int i = 0; i < n; i++) cin >> t, mp[t] = false;
    for (int i = 0; i < m; i++) cin >> t, mp[t] = true;
    cin >> k;
    for (map<int, bool>::iterator it = mp.begin(); it != mp.end(); ++it) {
      if (!it->second) {
        if (it->first != k)
          cout << "NO" << endl;
        else
          cout << "YES" << endl;
        break;
      }
    }
  }
  return 0;
}