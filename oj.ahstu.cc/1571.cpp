#include <stdio.h>
int main() {
  int m, n;
  scanf("%d", &m);
  while (m--) {
    scanf("%d", &n);
    printf("%d\n", n * (n + 1) * (n + 2) / 6);
  }
  return 0;
}
