#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b;
  getline(cin, a);
  getline(cin, b);
  a += b;
  string h;
  for (char c : a) {
    if (h.find(c) == string::npos) {
      cout << c;
      h.push_back(c);
    }
  }

  return 0;
}