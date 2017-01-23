#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int f(int n) {
  char s[100];
  sprintf(s, "%d", n);
  int i, j, len = strlen(s);
  int max = 0;
  for (i = 0; i < len; i++) {
    int temp = 0;
    for (j = 0; j < len; j++) {
      if (i == j) continue;
      temp = temp * 10 + s[j] - '0';
    }
    if (temp > max) max = temp;
  }
  return max;
}
int main() {
  int t, n;
  for (cin >> t; t-- && cin >> n; cout << f(n) << endl)
    ;
  return 0;
}
