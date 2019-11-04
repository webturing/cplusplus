#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  string b;
  cin >> a >> b;
  transform(a.begin(), a.end(), a.begin(), ::toupper);
  transform(b.begin(), b.end(), b.begin(), ::toupper);
  map<char, bool> M;
  for (char c : a) {
    if (b.find(c) == string::npos) {
      if (!M[c]) {
        cout << c;
        M[c] = true;
      }
    }
  }
  cout << endl;
  return 0;
}