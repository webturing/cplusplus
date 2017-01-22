#include <iostream>
using namespace std;

int main() {
  for (int n; cin >> n;) {
    int tot = 0;
    while (n > 1) {
      if (n % 2 == 0)
        n /= 2;
      else
        n = 3 * n + 1;
      ++tot;
    }
    cout << tot << endl;
  }
  return 0;
}