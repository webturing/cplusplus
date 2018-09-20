#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int tot = 0;
  for (int x = a; x <= b; x++)
    if (c % x == 0)
      ++tot;
  cout << tot << endl;
  return 0;
}