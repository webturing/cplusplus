#include <iostream>

using namespace std;

int main() {
  int a;
  cin >> a;
  cout << a << "*" << a << "*" << a << "=" << a* a* a << "=";
  int b = a * a - a + 1;
  cout << b;
  for (int i = 1; i < a; i++) cout << "+" << (b += 2);
  cout << endl;
  return 0;
}