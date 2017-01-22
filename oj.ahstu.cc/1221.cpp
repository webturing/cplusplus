#include <iostream>
#include <map>
#include <iterator>
using namespace std;
int main(int argc, char const *argv[]) {
  map<string, int> mp;
  int tot = 0;
  for (string s; cin >> s;) {
    ++tot;
    ++mp[s];
  }
  cout << tot << endl;
  for (map<string, int>::iterator it = mp.begin(); it != mp.end(); ++it)
    cout << it->first << ":" << it->second << endl;
  return 0;
}