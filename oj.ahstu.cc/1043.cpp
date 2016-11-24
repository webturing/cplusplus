#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  for (int m; cin >> m;) {
    double s = 1.;
    for (int i = 2; i <= m; i++) s -= 1. / i / i;
    cout << setiosflags(ios::fixed) << setprecision(6) << s << endl;
  }
  return 0;
}