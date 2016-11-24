#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  unsigned long long s, a, t;
  int i, n;
  for (cin >> a >> n, s = 0, i = 1, t = a; i <= n; i++) {
    s += t;
    t = t * 10 + a;
  }
  cout << s << endl;
  return 0;
}