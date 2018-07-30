#include <bits/stdc++.h>
using namespace std;
int Hash(string s) {
  int ret = 1;
  for (auto c : s) ret = ret * (c - 'A' + 1) % 47;
  return ret;
}
int main() {
  string a, b;
  cin >> a >> b;
  if (Hash(a) == Hash(b)) {
    cout << "GO" << endl;
  } else {
    cout << "STAY" << endl;
  }
  return EXIT_SUCCESS;
}