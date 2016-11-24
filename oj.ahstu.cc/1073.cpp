#include <iostream>
using namespace std;
void f(int n) {
  int tot = 0, five, two, one;
  for (five = 1; five <= n / 5; ++five)
    for (two = 1; two <= (n - 5 * five) / 2; ++two) {
      one = n - 5 * five - 2 * two;
      if (one > 0) ++tot;
    }
  cout << tot << endl;
}
int main() {
  for (int m; cin >> m; f(m))
    ;
  return 0;
}