#include <bits/stdc++.h>
using namespace std;
int main() {
  int S;
  cin >> S;
  int h = S / 3600;
  S %= 3600;
  int m = S / 60;
  int s = S % 60;
  cout << h << ":" << m << ":" << s << endl;
  return 0;
}