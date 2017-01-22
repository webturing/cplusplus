#include <iostream>

using namespace std;
int f(int n) {
  if (n == 1) return 0;
  if (n % 3 == 0)
    return f(n / 3) + 1;
  else
    return 1 + f(n / 3 + 1);
}
int main() {

  for (int n; cin >> n, n; cout << f(n) << endl)
    ;
  return 0;
}
