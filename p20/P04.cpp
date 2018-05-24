#include <bits/stdc++.h>
using namespace std;
bool FEQUAL(double x, double y) { return abs(x - y) < 1e-6; }
const int n = 100;
bool v[101][101];
void dfs(int a, int b, double fx, double fy, double fz) {
  int c = n - a - b;
  if (c < 0) return;
  if (FEQUAL(fx * a + fy * b + c * fz, n)) {
    printf("%d %d %d\n", a, b, c);
  }
  if (v[a + 1][b] == 0) {
    dfs(a + 1, b, fx, fy, fz);
    v[a + 1][b] = 1;
  }
  if (v[a][b + 1] == 0) {
    dfs(a, b + 1, fx, fy, fz);
    v[a][b + 1] = 1;
  }
  v[a][b] = 1;
}
int main(int argc, char const *argv[]) {
  // dfs(0, 0, 5, 3, 0.5);
  dfs(0, 0, 2, 4, 2.0 / 9);
  return 0;
}