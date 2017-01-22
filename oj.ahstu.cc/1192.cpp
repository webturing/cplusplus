#include <iostream>

using namespace std;

int main() {
  for (int n; cin >> n;) {
    int cur;
    cin >> cur;
    int prev = cur;
    int max = 1, subMax = 1;
    for (int i = 1; i <= n - 1; i++) {
      cin >> cur;
      if (cur == prev) ++subMax;
      if (subMax > max) max = subMax;
      if (cur != prev) {
        prev = cur;
        subMax = 1;
      }
    }
    cout << max << endl;
  }
  return 0;
}