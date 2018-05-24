#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  const string T("1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  int n = 16;
  // cin >> n;
  int M = 2 * n + 1;
  char c[M][M];
  memset(c, 0, sizeof(c));
  for (int x = 0; x < M; x++)
    for (int y = 0; y < M; y++) {
      if (abs(x - n) + abs(y - n) < n)
        c[x][y] = T[n - abs(x - n) - abs(y - n) - 1];
      else
        c[x][y] = ' ';
    }
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) {
      putchar(c[i][j]);
    }
    putchar('\n');
  }

  return 0;
}