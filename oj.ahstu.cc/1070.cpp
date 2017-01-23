/*
        Date: Sun Jan 22 2017 22:15:18 GMT+0800 (China Standard Time)
        Author: root
*/
#include <iostream>
using namespace std;
int main() {

  int e, n, m, x;
  cin >> e >> n >> m >> x;

  int a[n + 1], b[n + 1], c[n + 1];
  a[1] = e;
  b[1] = 0;
  c[1] = e;

  for (int k = 0; k < 1000; k++) {

    a[2] = k;
    b[2] = k;
    for (int i = 3; i < n; i++) {
      a[i] = a[i - 1] + a[i - 2];
      b[i] = a[i - 1];
    }

    for (int i = 2; i < n; i++) {
      c[i] = a[i] - b[i] + c[i - 1];
    }

    if (c[n - 1] == m) {
      break;
    }
  }
  cout << c[x] << endl;
  return 0;
}