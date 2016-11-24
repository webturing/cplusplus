#include <iostream>

using namespace std;

int main() {
  for (int a1, a2, b1, b2, c1, c2; cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2 &&
                                       (a1 || a2 || b1 || b2 || c1 || c2);
       cout << ((b1 - a1) * (c2 - b2) - (b2 - a2) * (c1 - b1) < 0) << endl)
    ;
  return 0;
}