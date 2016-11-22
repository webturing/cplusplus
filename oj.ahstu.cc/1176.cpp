#include <string>
#include <iostream>
using namespace std;
int count(const string& s, char c) {
  int tot = 0;
  for (int i = 0; i < s.length(); i++)
    if (s[i] == c) ++tot;
  return tot;
}
bool ok(const string& s) {
  return count(s, '4') == 0 && count(s, '6') + count(s, '8') >= 5;
}
int main() {
  int tot = 0;
  for (string s; cin >> s;)
    if (ok(s)) ++tot, cout << s << endl;
  cout << tot << endl;
  return 0;
}