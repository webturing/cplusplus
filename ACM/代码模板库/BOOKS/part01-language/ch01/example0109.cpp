#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int a, b;
  cin >> a >> b;
  a = a + b;
  b = a - b;
  a = a - b;
  cout << a << " " << b << endl;
  return 0;
}
// swap 2