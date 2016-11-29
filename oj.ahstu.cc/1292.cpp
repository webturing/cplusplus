#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
  ifstream cin("d:\\data\\1292\\sample.in");
  for (int a, b, c; cin >> a >> b >> c;) {
    bool find = false;
    for (int n = 10; n <= 100; n++)
      if (n % 3 == a && n % 5 == b && n % 7 == c) {
        find = true;
        cout << n << endl;
        break;
      }
    if (!find) cout << "No answer" << endl;
  }
  return 0;
}