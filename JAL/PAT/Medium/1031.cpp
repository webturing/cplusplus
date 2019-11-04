#include <bits/stdc++.h>
using namespace std;
const vector<int> w{7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
const string m("10X98765432");

int main() {
  ifstream cin("input.txt");
  int T;
  cin >> T;
  bool allPass = true;
  while (T--) {
    string s;
    cin >> s;
    int z = 0;
    for (size_t i = 0; i < s.size() - 1; i++) {
      z = (z + (s[i] - '0') * w[i]) % 11;
    }
    if (s.back() != m[z]) {
      cout << s << endl;
      allPass = false;
    }
  }
  if (allPass) cout << "All passed" << endl;
  return 0;
}