#include <bits/stdc++.h>
using namespace std;
int T, n, a, b, w;

int main() {
  for (scanf("%d", &T); T-- && ~scanf("%d", &n);) {
    int A = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &w);
      A ^= w;
    }
    for (int i = 0; i < n - 1; i++) scanf("%d%d", &a, &b);
    puts(A ? "Q" : "D");
  }
  return 0;
}