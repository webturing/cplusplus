#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[]) {
  // ifstream cin("data.in");
  for (int n, k, i; cin >> n >> k;) {
    for (i = 0; i < n; i++) {
      float house = 200 * pow(1 + k / 100., i);
      float w = n * (i + 1);
      if (w >= house) {
        printf("%d\n", i + 1);
        break;
      }
    }
    if (i == n) puts("Impossible");
  }

  return 0;
}