#include <iostream>
#include <string>
using namespace std;
int main() {
  for (string s; cin >> s;) {
    for (string::const_reverse_iterator it = s.rbegin(); it != s.rend(); ++it)
      cout << *it;
    cout << endl;
  }
  return 0;
}
