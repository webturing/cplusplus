#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
  ifstream cin("d:\\data\\1083\\test0.in");
  ofstream cout("d:\\data\\1125\\test0.out");
  for (int n; cin >> n;) {
    cout << n << "-->";
    if (n < 0) {
      cout << '-';
      n = -n;
    }
    for (int k = n ? (int)(log(n) / log(2)) : 0; k >= 0; k--) {
      cout << ((n >> k) & 1);
    }
    cout << endl;
  }
  return 0;
}