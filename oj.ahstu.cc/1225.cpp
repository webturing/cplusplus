#include <iostream>
#include <cctype>
using namespace std;
bool ok(string &s) {
  size_t len = s.length(), i;
  if (!isalpha(s[0]) && s[0] != '_') return false;
  for (i = 1; i < len; i++)
    if (!isalpha(s[i]) && !isdigit(s[i]) && s[i] != '_') return false;
  return true;
}
int main(int argc, char const *argv[]) {
  int n;
  string s;
  for (cin >> n, getline(cin, s); n-- && getline(cin, s);)
    cout << (ok(s) ? "yes" : "no") << endl;

  return 0;
}