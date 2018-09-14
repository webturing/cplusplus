#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  map<char, int> mp;
  while (getline(cin, s)) {
    for (int i = 0; i < s.length(); i++)
      mp[tolower(s[i])]++;
  }
  for (char c = 'a'; c <= 'z'; c++)
    cout << c << " : " << mp[c] << endl;
  return 0;
}