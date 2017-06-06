#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct node {
  int x, y;
} num[200000];
bool cmp(node a, node b) { return a.y < b.y; }
int main() {
  int t;
  scanf("%d", &t);
  int i, j;
  for (i = 0; i < t; i++) {
    scanf("%d%d", &num[i].x, &num[i].y);
  }
  int ans;
  sort(num, num + t, cmp);
  if (t % 2 == 1) {
    ans = 0;
    int zong = num[t / 2].y;
    for (i = 0; i < t; i++) {
      ans += abs(num[i].y - zong);
    }
  } else {
    int zong = num[t / 2].y + num[t / 2 - 1].y;
    zong /= 2;
    ans = 0;
    for (i = 0; i < t; i++) {
      ans += abs(num[i].y - zong);
    }
  }
  printf("%d\n", ans);
  return 0;
}