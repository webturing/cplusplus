#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <cctype>
using namespace std;
char max(string s) {
  char ret = s[0];
  for (int i = 1; i < s.length(); i++)
    if (s[i] > ret) ret = s[i];
  return ret;
}
int main(int argc, char const *argv[]) {
  ifstream cin("d:\\data\\1126\\sample.in");
  for (string s; cin >> s;) {
    char mx = max(s);
    for (string::const_iterator it = s.begin(); it != s.end(); ++it) {
      cout << *it;
      if (*it == mx) cout << "(max)";
    }
    cout << endl;
  }
  return 0;
}