#include <iostream>
#include <vector>
using namespace std;

int main() {
  for (int m, n; cin >> m >> n;) {
    vector<int> a(m), b(n);
    for (int i = 0; i < m; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int min = 0xffffff;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (abs(a[i] - b[j]) < min) min = abs(a[i] - b[j]);
    cout << min << endl;
  }
  return 0;
}