#include <iostream>

using namespace std;

int main() {
  for (unsigned n; cin >> n;) {
    bool start = true;
    while (n) {
      if (n % 2) start = !start;
      n /= 2;
    }
    cout << (start ? "even" : "odd") << endl;
  }

  return 0;
}
