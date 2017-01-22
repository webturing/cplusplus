#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]) {
  for (int m; cin >> m;)
    for (int n; m-- && cin >> n;) {
      vector<int> v(n);
      for (int i = 0; i < n; i++) cin >> v[i];
      sort(v.begin(), v.end());
      int dif = v[0] - v[1];
      bool ok = true;
      for (int i = 1; i < n - 1; i++)
        if (v[i] - v[i + 1] != dif) ok = false;
      cout << (ok ? "yes" : "no") << endl;
    }

  return 0;
}
