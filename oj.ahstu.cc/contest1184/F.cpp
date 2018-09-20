#include <cstdio>

int main() {
  for (int i = 0; i < 8; i++) {
    int x;
    scanf("%d", &x);
    printf("%o %x\n", x, x);
  }
  return 0;
}