#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  for (int a, b; cin >> a >> b && (a || b); cout << a + b << endl)
    ;
  return 0;
}
