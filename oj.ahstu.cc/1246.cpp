#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int m, n, t, s;
  for (cin >> m; m-- && cin >> n; cout << s << endl << endl)
    for (s = 0; n-- && cin >> t; s += t)
      ;
  return 0;
}