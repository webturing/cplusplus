#include <iostream>
using namespace std;
int B[] = {100, 50, 10, 5, 2, 1};
int main() {

  for (int n; cin >> n && n;) {
    int tot = 0;
    for (int m; n-- && cin >> m;) {
      for (int i = 0; i < 6; i++) tot += m / B[i], m %= B[i];
    }
    cout << tot << endl;
  }

  return 0;
}