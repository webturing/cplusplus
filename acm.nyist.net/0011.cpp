#include <iostream>

using namespace std;

int main() {
  for (int n; cin >> n;)
    for (int m; n-- && cin >> m;) {
      for (int i = 1; i <= m; i += 2) cout << i << " ";
      cout << endl;
      for (int i = 2; i <= m; i += 2) cout << i << " ";
      cout << endl;
      cout << endl;
    }
  return 0;
}
