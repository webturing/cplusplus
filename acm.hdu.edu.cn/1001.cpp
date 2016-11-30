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
  for (int n; ~SC(n); printf("%lld\n", 1LL * n * (n + 1) / 2))
    ;
  return 0;
}