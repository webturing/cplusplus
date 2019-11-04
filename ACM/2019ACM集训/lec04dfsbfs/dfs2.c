#include <stdio.h>
#define N 4
int a[N];
int used[N] = {0};

void dfs(int k) {
  if (k == N) {
    int i;
    for (i = 0; i < k; i++)
      if (used[i]) printf("%d ", a[i]);
    printf("\n");
    return;
  }
  int i;
  for (i = 0; i < N; i++)
    if (used[i] == 0) {
      used[i] = 1;
      a[i] = k;
      dfs(k + 1);
      used[i] = 0;
    }
}
int main() {
  dfs(0);
  return 0;
}
