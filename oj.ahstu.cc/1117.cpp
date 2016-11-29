#include <iostream>
#include <fstream>
using namespace std;
int main() {
  ifstream cin("d:\\data\\1117\\sample.in");
  for (int a, b; cin >> a >> b && !(a == 0 && b == 0);) {
    bool first = true;
    for (int n = a * 100; n <= a * 100 + 99; n++) {
      if (n % b == 0) {
        if (!first) {
          cout << " " << n / 10 % 10 << n % 10;
        } else {
          cout << n / 10 % 10 << n % 10;
          first = false;
        }
      }
    }
    cout << endl;
  }
  return 0;
}