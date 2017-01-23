#include <iostream>
#include <algorithm>

using namespace std;
bool check(string s, int i) {
  string keyword = s.substr(0, i);
  for (size_t j = i; j < s.length(); j += i) {
    if (s.substr(j, i) != keyword) return false;
  }
  return true;
}
int main(int argc, char const *argv[]) {
  for (string s; cin >> s;) {
    size_t len = s.length(), i;
    for (i = 1; i <= s.length(); i++) {
      if (len % i == 0 && check(s, i)) break;
    }
    cout << i << endl;
  }

  return 0;
}
