#include <bits/stdc++.h>

using namespace std;

void split(const string &s, const string &delim, vector<string> &ret) {
  size_t last = 0;
  size_t index = s.find_first_of(delim, last);
  while (index != string::npos) {
    ret.push_back(s.substr(last, index - last));
    last = index + 1;
    index = s.find_first_of(delim, last);
  }
  if (index - last > 0) {
    ret.push_back(s.substr(last, index - last));
  }
}

bool ok(const string &s) {
  for (auto it = s.begin(); it != s.end(); ++it)
    if (!isdigit(*it)) return false;
  int m;
  istringstream iss(s);
  iss >> m;
  return m <= 255 && m >= 0;
}

bool ok(vector<string> &v) {
  for (auto it = v.begin(); it != v.end(); ++it)
    if (!ok(*it)) return false;
  return true;
}

int main(int argc, char const *argv[]) {
  for (string s; getline(cin, s);) {
    vector<string> ip;
    split(s, ".", ip);
    cout << (ok(ip) ? "Y" : "N") << endl;
  }
  return 0;
}