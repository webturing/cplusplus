#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a + 3);
  if (a[0] + a[1] <= a[2])
    cout << "not a triangle\n";
  else if (a[0] * a[0] + a[1] * a[1] == a[2] * a[2])
    cout << "yes\n";
  else
    cout << "no\n";
  return 0;
}