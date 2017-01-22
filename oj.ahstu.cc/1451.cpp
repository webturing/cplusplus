#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  for (int n; cin >> n;) {
    int m = n, s = 0;
    while (n) s += n % 10, n /= 10;
    cout << (m % s ? "no" : "yes") << endl;
  }
  return 0;
}