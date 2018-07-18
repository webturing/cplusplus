#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
      if (i == 1 || i == m)
        cout << "X";
      else
        cout << " ";
    cout << endl;
    while (n--) {
      for (int i = 2; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
          if (j == i || j == m - i + 1) {
            cout << "X";
            if (j > m / 2) break;
          } else {
            cout << " ";
          }
        }
        cout << endl;
      }
    }
    cout << endl;
  }
  return 0;
}