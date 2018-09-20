#include <cstdio>

int main() {
  double s = 0;
  for (int i = 1; i <= 100; i++) {
    if (i & 1)
      s += 1.0 / i;
    else
      s -= 1.0 / i;
  }
  printf("%.8f\n", s);
  return 0;
}