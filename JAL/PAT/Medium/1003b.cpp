#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool ok(string &s) {
  for (auto c : s)
    if (c != 'P' && c != 'A' && c != 'T') return false;
  if (s.find("PAT") == string::npos) return false;
  int left = s.find("PAT"), right = s.find("");

  return false;
}

int main() {
  ifstream cin("input.txt");
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    if (ok(s))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
