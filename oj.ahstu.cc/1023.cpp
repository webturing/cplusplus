#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[]) {
  int mx = -0xfffffff;
  for (int n; cin >> n && ~n;)
    if (mx < n) mx = n;
  cout << mx << endl;
  return 0;
}
