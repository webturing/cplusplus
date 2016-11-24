#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
  int n, t, s;
  for (; cin >> n && n; cout << s << endl)
    for (s = 0; n-- && cin >> t; s += t)
      ;
  return 0;
}