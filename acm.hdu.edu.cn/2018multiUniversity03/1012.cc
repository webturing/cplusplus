#include <bits/stdc++.h>
using namespace std;
char p[100][100];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int x, y, z;
    cin >> x >> y >> z;
    int m = 2 * x + 2 * y + 1, n = 2 * y + 2 * z + 1;
    for (int i = 0; i < 2 * y; i += 2) {
      for (int j = 0; j < m; j++) {
        if (j % 2 == 0)
          p[i][j] = '+';
        else
          p[i][j] = '-';
      }
    }
    for (int i = 1; i < 2 * y; i += 2) {
      for (int j = 0; j < m; j++) {
        if (j % 2 == 0)
          p[i][j] = '.';
        else
          p[i][j] = '/';
      }
    }
    for (int i = 2 * y; i < n; i += 2) {
      for (int j = 0; j < 2 * x + 1; j++) {
        if (j % 2 == 0)
          p[i][j] = '+';
        else
          p[i][j] = '-';
      }
    }
    for (int i = 2 * y + 1; i < n; i += 2) {
      for (int j = 0; j < 2 * x + 1; j++) {
        if (j % 2 == 0)
          p[i][j] = '|';
        else
          p[i][j] = '.';
      }
    }
    for (int i = 2 * y; i < n; i += 2) {
      for (int j = 2 * x + 1; j < m; j++) {
        if (j % 2 == 0)
          p[i][j] = '+';
        else
          p[i][j] = '.';
      }
    }
    for (int i = 2 * y + 1; i < n; i += 2) {
      for (int j = 2 * x + 1; j < m; j++) {
        if (j % 2 == 0)
          p[i][j] = '|';
        else
          p[i][j] = '/';
      }
    }
    for (int i = 0; i < 2 * y; i++) {
      for (int j = m - i; j < m; j += 2) {
        if (p[i][j] == '.') p[i][j] = '|';
      }
    }
    for (int i = 0; i < 2 * y; i++) {
      for (int j = m - i - 1; j < m; j++) {
        if (p[i][j] == '-') p[i][j] = '.';
      }
    }
    for (int i = 0; i < 2 * y; i++) {
      for (int j = 0; j < 2 * y - i; j++) p[i][j] = '.';
    }
    for (int i = n - 1; i >= n - 2 * y; i--) {
      for (int j = m + n - i - 1 - 2 * y; j < m; j++) p[i][j] = '.';
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) cout << p[i][j];
      cout << endl;
    }
  }
  return 0;
}