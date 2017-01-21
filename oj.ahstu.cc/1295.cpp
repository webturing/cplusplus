#include <iostream>
#include <iomanip>
using namespace std;
int main(int argc, char const *argv[]) {
  for (int n; cin >> n;) {
    double s = 0;
    for (int i = 1; i <= n; i++) s += 1. / i;
    cout << setiosflags(ios::fixed) << setprecision(3) << s << endl;
  }
  return 0;
}