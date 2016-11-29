#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
  ifstream cin("d:\\data\\1289\\sample.in");
  int sum, count, max, min;
  sum = count = max = 0;
  min = 0xfffff;
  for (int n; cin >> n; ++count) {
    sum += n;
    if (n > max) max = n;
    if (n < min) min = n;
  }
  printf("%d %d %.3f\n", min, max, sum * 1.0 / count);
  return 0;
}