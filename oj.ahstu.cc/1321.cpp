#include <iostream>
#include <map>
using namespace std;
int main(int argc, char const *argv[]) {
  for (int n; cin >> n;) {
    map<float, int> mp;
    for (int x, y; n-- && cin >> x >> y;) ++mp[x * 1.0 / y];
    int max = 0;
    for (map<float, int>::iterator it = mp.begin(); it != mp.end(); ++it)
      if (it->second > max) max = it->second;
    cout << max << endl;
  }
  return 0;
}