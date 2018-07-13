#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int cas, ok, len;
  string s;
  for (cin >> cas; cas-- && cin >> s;) {
    for (len = s.length(), ok = true; len && !(len & 1) && ok;) {
      ok = true;
      for (int i = 0; i < len / 2; i++)
        if (s[i] != s[len - 1 - i]) {
          ok = false;
          break;
        }
      if (ok) len >>= 1;
    }
    cout << len << endl;
  }

  return 0;
}