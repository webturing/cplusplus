#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[]) {
  int a, b, c;
  cin >> a >> b >> c;
  cout << setiosflags(ios::fixed) << setprecision(3) << (a + b + c) / 3.
       << endl;
  return 0;
}
