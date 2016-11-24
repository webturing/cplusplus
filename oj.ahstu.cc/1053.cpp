#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <cctype>
using namespace std;
bool inside(char c, string s) {
  for (string::const_iterator it = s.begin(); it != s.end(); ++it)
    if (*it == c) return true;
  return false;
}
bool ok(string s) {
  int len = s.length();
  if (len < 8 || len > 16) return 0;
  int upper, lower, digit, special;
  upper = lower = digit = special = 0;
  for (string::const_iterator it = s.begin(); it != s.end(); ++it)
    if (isupper(*it))
      upper = 1;
    else if (islower(*it))
      lower = 1;
    else if (isdigit(*it))
      digit = 1;
    else if (inside(*it, "~,!,@,#,$,%%,^; "))
      special = 1;
  return upper + lower + digit + special >= 3;
}
int main(int argc, char const *argv[]) {
  ifstream cin("d:\\data\\1053\\sample.in");
  int M;
  string s;
  for (cin >> M; M-- && cin >> s; cout << (ok(s) ? "YES" : "NO") << endl)
    ;
  return 0;
}