#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[]) {
  for (int n; cin >> n;) cout << 1 + (int)(log(n) / log(3)) << endl;
  return 0;
}
