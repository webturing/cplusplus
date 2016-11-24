#include <iostream>

using namespace std;

bool prime(int n) {
  if (n == 2) return true;
  if (n < 2 || n % 2 == 0) return false;
  for (int c = 3; c * c <= n; c += 2)
    if (n % c == 0) return false;
  return true;
}

int main(int argc, char const *argv[]) {
  for (int n; cin >> n; cout << prime(n) << endl)
    ;
  return 0;
}
