#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
  for (int n; cin >> n && n;) {
    map<string, int> mp;
    string s;
    for (int i = 0; i < n; i++) {
      cin >> s;
      ++mp[s];
    }
    map<string, int>::iterator it = mp.begin(), max = it;
    for (++it; it != mp.end(); ++it) {
      if (it->second > max->second) max = it;
    }
    cout << max->first << endl;
  }
  return 0;
}
