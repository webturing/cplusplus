#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[]) {
  for (int n; cin >> n;) {
    float d = atan(1.0) * 4 * n / 180;
    cout << setiosflags(ios::fixed) << setprecision(3) << sin(d) << " "
         << cos(d) << endl;
  }

  return 0;
}
