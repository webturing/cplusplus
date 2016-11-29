#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
  ifstream cin("d:\\data\\1179\\sample.in");
  int n, a, b, c;
  for (cin >> n; n-- && cin >> a >> b >> c;) {
    if (a + b == c)
      printf("%d+%d=%d\n", a, b, c);
    else if (a - b == c)
      printf("%d-d=%d\n", a, b, c);
    else if (b - a == c)
      printf("%d-%d=%d\n", b, a, c);
    else if (a * b == c)
      printf("%d*%d=%d\n", a, b, c);
    else if (a == b * c)
      printf("%d/d=%d\n", a, b, c);
    else if (b == a * c)
      printf("%d/%d=%d\n", b, a, c);
    else
      puts("None");
  }
  return 0;
}