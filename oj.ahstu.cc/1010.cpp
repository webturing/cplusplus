#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int n, a, b, c;
  cin >> n;
  c = n % 10, b = (n / 10) % 10, a = n / 100;
  cout << (n == a * a * a + b * b * b + c * c * c) << endl;
  return 0;
}
