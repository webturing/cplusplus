#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  string s;
  for (cin >> n; n-- && cin >> s;) {
    char cur = s[0];
    int freq = 1;
    for (string::const_iterator it = s.begin() + 1; it != s.end(); ++it) {
      if (*it == cur)
        ++freq;
      else {
        cout << freq << cur;
        freq = 1;
        cur = *it;
      }
    }
    cout << freq << cur << endl;
  }

  return 0;
}