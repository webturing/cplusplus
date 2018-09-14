#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  while (cin >> s) {
    if (s == "0")
      break;
    int t = 0;
    for (int i = 0; i < s.length(); i++)
      t += s[i] - '0';
    cout << t << endl;
  }
  return 0;
}