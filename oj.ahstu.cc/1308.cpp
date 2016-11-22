#include <iostream>
#include <cstdio>
using namespace std;
int main() {
  int a = 2, b = 1, c;
  float f[21] = {0};
  for (int i = 1; i <= 20; i++) f[i] = 1.0 * a / b, c = a + b, b = a, a = c;
  for (int i = 1; i <= 20; i++) f[i] += f[i - 1];
  for (int n; cin >> n; printf("%.3f\n", f[n]))
    ;

  return 0;
}