
#include <stdio.h>
void input(int a[], int n, int m, int sum) {
  int i;
  for (i = sum - m; i < sum; i++) a[i] = n;
}
void putss(int a[], int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    printf("%d", a[i * n]);
    for (j = i * n + 1; j < (i + 1) * n; j++) printf(" %d", a[j]);
    printf("\n");
  }
}
int main() {
  int N, i, sum = 0;
  scanf("%d", &N);
  int a[N * N];
  for (i = 0; i < N * N; i++) a[i] = 0;
  while (1) {
    int n, m;
    scanf("%d%d", &n, &m);
    if (n == 0 && m == 0) break;
    sum += m;
    input(a, n, m, sum);
  }
  putss(a, N);
  return 0;
}