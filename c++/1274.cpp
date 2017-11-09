#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a + 3);
  cout << a[0] << " " << a[1] << " " << a[2] << endl;
  return 0;
}