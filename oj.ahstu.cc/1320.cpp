#include <iostream>

using namespace std;

int f(int x) {
  if (x == 0) return 1;
  return f(x - 1) + 2 * (x - 1);
}

int main() {
  int n, x;
  for (cin >> n; n-- && cin >> x; cout << f(x) << endl)
    ;

  return 0;
}