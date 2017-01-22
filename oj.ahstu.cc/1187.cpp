#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  for (int a1, b1, a2, b2; cin >> a1 >> b1 >> a2 >> b2;) {
    int n;
    for (n = 1;; n++) {
      if (n % a1 == b1 && n % a2 == b2) break;
    }
    cout << n << endl;
  }
  return 0;
}