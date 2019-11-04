#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned a, b;
  cin >> a >> b;
  bitset<32> A(a), B(b);
  cout << A << endl;
  cout << B << endl;
  cout << (A ^ B) << endl;
  return 0;
}