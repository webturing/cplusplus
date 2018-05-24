
#include <iostream>
using namespace std;
int main() {
  for (int a, b; cin >> a >> b && (a || b); cout << a + b << endl)
    ;
  return 0;
}
