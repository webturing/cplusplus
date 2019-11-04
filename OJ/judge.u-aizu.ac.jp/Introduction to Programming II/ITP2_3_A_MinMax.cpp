#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << min(a, min(b, c)) << " " << max(a, max(b, c)) << endl;
  return 0;
}