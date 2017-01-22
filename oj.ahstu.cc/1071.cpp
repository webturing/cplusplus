#include <iostream>

using namespace std;
int f(int n) {
  if (n == 0) return 3;
  return 2 * (f(n - 1) - 1);
}
int main(int argc, char const *argv[]) {
  int m, n;
  for (cin >> m; m-- && cin >> n; cout << f(n) << endl)
    ;
  return 0;
}