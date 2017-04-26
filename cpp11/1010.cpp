
#include <iostream>
using namespace std;
#define CUBE(x) ((x) * (x) * (x))
int main() {
  int n;
  cin >> n;
  auto flag = (n < 1000 && n >= 100);
  if (flag) {
    auto a = n / 100, b = n % 100 / 10, c = n % 10;
    flag = (n == CUBE(a) + CUBE(b) + CUBE(c));
  }
  cout << flag << endl;
  return 0;
}
