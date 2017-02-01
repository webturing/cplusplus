#include <iostream>
#include <cstdio>
using namespace std;
int a[10];
int n, p;
int main() {
  scanf("%d%d", &n, &p);
  while (1) {
    for (int i = 0; i < n; i++) {
      for (int j = n - 1; j > 0; j--) {
        if (a[j] + 1 == p + 1) {
          a[j] = 0;
          a[j - 1]++;
        }
      }
      if (a[0] + 1 > p) return 0;
      cout << a[i] + 1;
    }

    a[n - 1]++;
    printf("\n");
  }
}