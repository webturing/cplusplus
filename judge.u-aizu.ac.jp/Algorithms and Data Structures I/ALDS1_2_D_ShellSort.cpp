#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1000005;
int n;
int a[maxn];
int cnt;
vector<int> G;
void InsertSort(int g) {
  for (int i = g; i < n; i++) {
    int temp = a[i];
    int loc = i - g;
    while (loc >= 0 && a[loc] > temp) {
      a[loc + g] = a[loc];
      loc -= g;
      cnt++;
    }
    a[loc + g] = temp;
  }
}
void ShellSort() {
  int h = 1;
  while (h <= n) {
    G.push_back(h);
    h = 3 * h + 1;
  }
  for (int i = G.size() - 1; i >= 0; i--) {
    InsertSort(G[i]);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  cnt = 0;
  ShellSort();
  printf("%d\n", G.size());
  for (int i = G.size() - 1; i >= 0; i--)
    printf("%d%c", G[i], i == 0 ? '\n' : ' ');
  printf("%d\n", cnt);
  for (int i = 0; i < n; i++) printf("%d\n", a[i]);
  return 0;
}