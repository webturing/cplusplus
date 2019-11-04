#include <bits/stdc++.h>
using namespace std;
int main() {
  map<char, int> M;
  for (char c; cin >> c; M[tolower(c)]++)
    ;
  char m = 'a';
  for (char c = 'b'; c <= 'z'; ++c) {
    if (M[c] > M[m]) m = c;
  }

  cout << m << " " << M[m] << endl;
  return 0;
}