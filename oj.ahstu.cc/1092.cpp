#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <fstream>
using namespace std;
bool sys(int M) {
  char s[100];
  sprintf(s, "%d", M);
  int n = strlen(s);
  for (int i = 0; i < n / 2; i++)
    if (s[i] != s[n - 1 - i]) return false;
  return true;
}
int rev(int n) {
  int ret = 0;
  while (n) ret = ret * 10 + n % 10, n /= 10;
  return ret;
}
int main(int argc, char const *argv[]) {
  ifstream cin("d:\\data\\1092\\sample.in");
  int L, M;
  for (cin >> L; L-- && cin >> M;) {
    int find = 0;
    for (int i = 0; i < 8; i++) {
      if (sys(M)) {
        find = 1;
        cout << i << endl;
        break;
      }
      M = M + rev(M);
    }
    if (!find) cout << find << endl;
  }
  return 0;
}