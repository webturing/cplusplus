
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main() {

  bool first = true;
  int a[4];
  int t;

  for (cin >> t; t-- && cin >> a[0] >> a[1] >> a[2] >> a[3];) {
    vector<int> v;
    if (!first)
      printf("\n");
    else {
      first = false;
    }
    sort(a, a + 4);
    do {
      v.push_back(a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3]);
    } while (next_permutation(a, a + 4));
    cout << v[0];
    int k = v[0] / 1000;
    for (size_t i = 1; i < v.size(); i++) {
      if (v[i] / 1000 == k) {
        printf(" %d", v[i]);
      } else {
        printf("\n");
        printf("%d", v[i]);
        k = v[i] / 1000;
      }
    }
    printf("\n");
  }
  return 0;
}