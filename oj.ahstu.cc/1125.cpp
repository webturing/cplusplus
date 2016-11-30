#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
long long Q[30][30] = {0};

long long cnr(int n, int r) {

  if (Q[n][r]) return Q[n][r];
  if (n == r || r == 0) return Q[n][r] = 1;
  return Q[n][r] = cnr(n - 1, r - 1) + cnr(n - 1, r);
}
int main() {
  ifstream cin("d:\\data\\1125\\sample.in");
  ofstream cout("d:\\data\\1125\\sample.out");
  for (int n; cin >> n;) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        if (j) cout << ' ';
        cout << cnr(i, j);
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}