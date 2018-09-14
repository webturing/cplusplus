#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int cnt = 0;
  for (int x = a; x <= b; x++)
    if (c % x == 0) ++cnt;
  cout << cnt << endl;
  return 0;
}