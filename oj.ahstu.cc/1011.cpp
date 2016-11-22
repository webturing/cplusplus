#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
  for (int n = 100; n <= 999; n++) {
    int c = n % 10, b = n / 10 % 10, a = n / 100;
    if (n == a * a * a + b * b * b + c * c * c) cout << n << endl;
  }
  return 0;
}
