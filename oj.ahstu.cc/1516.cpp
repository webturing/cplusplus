#include <iostream>
#include <map>
using namespace std;
map<char, int> stat(string& s) {
  map<char, int> mp;
  for (string::const_iterator it = s.begin(); it != s.end(); ++it) ++mp[*it];
  return mp;
}
int getDotaer(map<char, int> mp) {
  int min = mp['d'];
  if (mp['o'] < min) min = mp['o'];
  if (mp['t'] < min) min = mp['t'];
  if (mp['a'] < min) min = mp['a'];
  if (mp['e'] < min) min = mp['e'];
  if (mp['r'] < min) min = mp['r'];
  return min;
}
int getLoler(map<char, int> mp) {
  int min = mp['l'] / 2;
  if (mp['o'] < min) min = mp['o'];
  if (mp['e'] < min) min = mp['e'];
  if (mp['r'] < min) min = mp['r'];
  return min;
}
int main() {
  for (string dotaer, loler; cin >> dotaer >> loler;) {
    int fd = getDotaer(stat(dotaer));
    int fl = getLoler(stat(loler));
    cout << "Dotaer: " << fd << endl;
    cout << "Loler: " << fl << endl;
    if (fl > 3 * fd)
      cout << "Loler win" << endl;
    else
      cout << "Dotaer win" << endl;
  }

  return 0;
}