#include <iostream>
#include <map>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[]) {
  ifstream cin("d:\\data\\1075\\test0.in");
  int n, t;
  map<int, int> mp;
  for (cin >> n; n-- && cin >> t; ++mp[t])
    ;
  int k = t, mx = mp[k];
  for (map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it)
    if (it->second > mx) {
      k = it->first;
      mx = mp[k];
    }
  cout << k << endl << mx << endl;
  return 0;
}