#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
  LL a, b;
  cin >> a >> b;
  LL c = a * b;
  LL d = 0;
  do {
    d = d * 10 + c % 10;
    c /= 10;
  } while (c > 0);
  cout << d << endl;
  return 0;
}