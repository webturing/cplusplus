#include <stdio.h>
#include <algorithm>
using namespace std;
const int MOD = 1e9;
int gcd(int a, int b) {
  if (a == 0 && b == 0) return 1;
  return b == 0 ? a : gcd(b, a % b);
}
int gcd(int a, int b, int c, int d) { return gcd(gcd(a, b), gcd(c, d)); }
int T;
int n, m;
int a[100];
int v[100];
int main() {

  freopen("input.txt", "r", stdin);
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0; i < m; i++) scanf("%d", v + i);
    int s = 1;
    for (int i = 0; i < n - 3; i++)
      s = v[gcd(a[i], a[i + 1], a[i + 2], a[i + 3])] * s % (MOD);

    printf("%d\n", s);
  }
}