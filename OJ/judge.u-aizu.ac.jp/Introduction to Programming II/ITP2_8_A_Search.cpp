#include <bits/stdc++.h>
using namespace std;
int main() {
  ifstream cin("in.txt");
  map<string, int> mp;
  int q;
  cin >> q;
  while (q--) {
    int op;
    cin >> op;
    if (op == 0) {
      string name;
      int val;
      cin >> name >> val;
      mp[name] = val;
    } else if (op == 1) {
      string name;
      cin >> name;
      cout << mp[name] << endl;
    }
  }

  return 0;
}