
#include <stdio.h>
int main() {
  int N;
  while (scanf("%d", &N) == 1) {
    int i, a, b = N, tot = 0;
    int flog = 1;
    for (i = 1;; i++) {
      if (b == 0) break;
      a = b % 10;
      b /= 10;
      if (a == 0) {
        flog = 0;
        printf("Unlucky\n");
        break;
      }
    }
    if (flog) {

      for (i = 1; i <= N; i++) {
        int flag = 1, j;
        b = i;
        for (j = 1;; j++) {
          a = b % 10;
          b /= 10;
          if (a == 0) {
            flag = 0;
            break;
          }
          if (b == 0) break;
        }
        if (flag) tot = tot + 1;
      }
      printf("%d\n", tot);
    }
  }

  return 0;
}