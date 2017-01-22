#include <iostream>
using namespace std;
int main() {
  for (int vul, d; cin >> vul >> d;) {
    int k = (vul + d - 1) / d;
    int m = 0;
    while (m * (m + 1) / 2 < k) ++m;
    cout << k + m - 1 << endl;
  }

  return 0;
}