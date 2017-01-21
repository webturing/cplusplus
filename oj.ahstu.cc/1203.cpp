
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
  char s[1000];
  gets(s);
  int i = 0, n = strlen(s), tot = 0;
  while (!isalpha(s[i]) && i < n) ++i;
  for (; i < n;) {
    while (isalpha(s[i]) && i < n) {
      putchar(s[i]);
      i++;
    }
    ++tot;
    while (!isalpha(s[i]) && i < n) ++i;
    putchar('\n');
  }
  return 0;
}
