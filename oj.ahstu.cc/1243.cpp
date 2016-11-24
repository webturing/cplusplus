#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int n, m, t, s;
  for (cin >> n; n-- && cin >> m; cout << s << endl)
    for (s = 0; m-- && cin >> t; s += t)
      ;
  return 0;
}