#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SC(x) scanf("%d", &x)
typedef long long LL;
using namespace std;
//#define JUDGE_MOD
int main() {
#ifdef JUDGE_MOD
  freopen("data.in", "r", stdin);
#endif
  int t, cas;
  char A[1001], B[1001], C[1001];
  for (SC(t), cas = 0; t-- && scanf("%s%s", A, B); cas++) {
    memset(C, 0, sizeof(C));
    int sc = 0, la = strlen(A), lb = strlen(B), a, b, i;
    for (i = 0; i < MAX(la, lb); i++) {
      if (la <= i)
        a = 0;
      else
        a = A[la - i - 1] - '0';
      if (lb <= i)
        b = 0;
      else
        b = B[lb - i - 1] - '0';
      int c = sc + a + b;
      sc = c / 10;
      C[i] = c % 10 + '0';
    }
    if (sc) C[i] = '1';
    int lc = strlen(C);
    for (int i = 0; i < lc / 2; i++) swap(C[i], C[lc - 1 - i]);
    if (cas) printf("\n");
    printf("Case %d:\n", cas + 1);

    printf("%s + %s = %s\n", A, B, C);
  }
  return 0;
}