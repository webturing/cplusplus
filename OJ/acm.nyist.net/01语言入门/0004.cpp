#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  for (int n; cin >> n;)
    for (string s; n-- && cin >> s;) {
      sort(s.begin(), s.end());
      cout << s[0] << " " << s[1] << " " << s[2] << endl;
    }
  return 0;
}
