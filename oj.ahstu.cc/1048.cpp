#include <iostream>

using namespace std;

int f(int n) {
  int s = 0;
  for (int i = 1; i < n; i++)
    if (n % i == 0) s += i;
  return s;
}

int main() {
  int n, a, b;
  for (cin >> n; n-- && cin >> a >> b;
       cout << (f(a) == b && f(b) == a ? "YES" : "NO") << endl)
    ;
  return 0;
}
