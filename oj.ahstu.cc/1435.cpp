#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <stack>
#include <map>
using namespace std;
const int maxn = 1005;
char a_a[maxn];
char a_b[maxn];
char b_a[maxn];
char b_b[maxn];
char temp[2 * maxn];
void Do() {
  memset(a_a, 0, sizeof(a_a));
  memset(a_b, 0, sizeof(a_b));
  memset(b_a, 0, sizeof(b_a));
  memset(b_b, 0, sizeof(b_b));
  scanf("%s", temp);
  sscanf(temp, "%[a-z].%[a-z]", a_a, a_b);
  scanf("%s", temp);
  sscanf(temp, "%[a-z].%[a-z]", b_a, b_b);
  int xs = max(strlen(a_b), strlen(b_b));
  int zs = max(strlen(a_a), strlen(b_a));
  int size_a_a = strlen(a_a);
  int size_a_b = strlen(a_b);
  int size_b_a = strlen(b_a);
  int size_b_b = strlen(b_b);
  for (int i = 0; i < size_a_a; i++) a_a[i] -= 'a';
  for (int i = 0; i < size_a_b; i++) a_b[i] -= 'a';
  for (int i = 0; i < size_b_a; i++) b_a[i] -= 'a';
  for (int i = 0; i < size_b_b; i++) b_b[i] -= 'a';
  if (zs != size_a_a) {
    int i;
    for (i = zs - 1; i >= zs - size_a_a; i--) a_a[i] = a_a[i - zs + size_a_a];
    for (; i >= 0; i--) a_a[i] = 0;
  }
  if (zs != size_b_a) {
    int i;
    for (i = zs - 1; i >= zs - size_b_a; i--) b_a[i] = b_a[i - zs + size_b_a];
    for (; i >= 0; i--) b_a[i] = 0;
  }
  int jw = false;
  for (int i = xs - 1; i >= 0; i--) {
    a_b[i] += b_b[i] + jw;
    jw = false;
    if (a_b[i] >= 26) {
      a_b[i] %= 26;
      jw = true;
    }
  }
  for (int i = zs - 1; i >= 0; i--) {
    a_a[i] += b_a[i] + jw;
    jw = false;
    if (a_a[i] >= 26) {
      a_a[i] %= 26;
      jw = true;
    }
  }
  int zs_b = -1;
  for (int i = 0; i < zs; i++) {
    if (a_a[i] != 0) {
      zs_b = i;
      break;
    }
  }
  int xs_e = -1;
  for (int i = xs - 1; i >= 0; i--) {
    if (a_b[i] != 0) {
      xs_e = i;
      break;
    }
  }
  if (jw == false) {
    if (zs_b == -1) {
      putchar('a');
    } else {
      for (int i = zs_b; i < zs; i++) putchar(a_a[i] + 'a');
    }
  } else {
    putchar('b');
    for (int i = 0; i < zs; i++) putchar(a_a[i] + 'a');
  }
  if (xs_e != -1) {
    putchar('.');
    for (int i = 0; i <= xs_e; i++) putchar(a_b[i] + 'a');
  }
  putchar('\n');
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) Do();
  return 0;
}