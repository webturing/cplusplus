#include <stdio.h>
int main() {
  int m;
  char s[100];
  scanf("%d", &m);
  while (m--) {
    scanf("%s", s);
    printf("%s\n", s);
  }
  return 0;
}
