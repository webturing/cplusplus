#include <iostream>
#include <cmath>

using namespace std;
bool cube(int n) {
  if (n < 0) n *= -1;
  int x = pow(n, 1.0 / 3) + .5;
  return x * x * x == n;
}
int main(int argc, char const *argv[]) {

  int tot = 0;
  for (int n; cin >> n && n; tot += cube(n))
    ;
  cout << tot << endl;

  return 0;
}
