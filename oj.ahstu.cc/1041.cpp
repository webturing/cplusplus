
#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>
using namespace std;
int main() {
  for (int n; cin >> n;) {
    auto s = 0.0;
    for (auto i = 1; i <= n; i++) s += 1.0 / i;
    cout << setiosflags(ios::fixed) << setprecision(6) << s << endl;
  }
  return 0;
}
