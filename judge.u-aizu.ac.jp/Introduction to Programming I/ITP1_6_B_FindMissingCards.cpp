#include <bits/stdc++.h>
using namespace std;

int main() {
  map<int, set<string>> mp;
  for (int i = 1; i <= 13; i++) {
    mp[i].insert("S");
    mp[i].insert("H");
    mp[i].insert("C");
    mp[i].insert("D");
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string kind;
    int digit;
    cin >> kind >> digit;
    mp[digit].erase(kind);
  }
  string kind[] = {"S", "H", "C", "D"};
  for (int k = 0; k < 4; k++)
    for (int i = 1; i <= 13; i++) {
      if (mp[i].find(kind[k]) != mp[i].end())
        cout << kind[k] << " " << i << endl;
    }
  return 0;
}