#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  ifstream cin("sort3.in");

  int a, b, c;
  while (cin >> a >> b >> c) {
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
    cout << a << " " << b << " " << c << endl;
  }
  return 0;
}
