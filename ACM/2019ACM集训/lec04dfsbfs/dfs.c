#include <stdio.h>
#define N 4
int a[N];
int used[N] = {0};
void fill() {
  int i;
  for (i = 0; i < 4; i++) a[i] = i + 1;
}
void dfs(int k) {
  if (k == N) {
    int i;
    for (i = 0; i < k; i++)
      if (used[i]) printf("%d ", a[i]);
    printf("\n");
    return;
  }
  used[k] = 1;
  dfs(k + 1);
  used[k] = 0;
  dfs(k + 1);
}
int main() {
  fill();
  dfs(0);
  return 0;
}
