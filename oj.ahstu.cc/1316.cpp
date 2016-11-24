#include <iostream>
using namespace std;
int main() {
  int n, a, b;
  for (cin >> n; n-- && cin >> a >> b;
       cout << (a + b) * (a + b + 1) / 2 + a + 1 << endl)
    ;
  return 0;
}