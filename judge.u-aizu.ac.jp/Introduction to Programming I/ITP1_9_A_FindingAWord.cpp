#include <bits/stdc++.h>
using namespace std;

int main() {
  string key;
  cin >> key;
  transform(key.begin(), key.end(), key.begin(), ::tolower);
  int cnt = 0;
  for (string s; cin >> s;) {
    if (s == "END_OF_TEXT") break;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    if (s == key) ++cnt;
  }
  cout << cnt << endl;
  return 0;
}