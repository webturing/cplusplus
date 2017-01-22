#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {

  int N;
  cin >> N;
  while (N--) {
    string s;
    cin >> s;
    int x = s[0] - 'a' + 1, y = s[1] - '0', tot = 0;
    for (int i = 1; i <= 8; i++)
      for (int j = 1; j <= 8; j++) {
        int dx = abs(x - i), dy = abs(y - j);
        if (dx * dx + dy * dy == 5) {
          ++tot;
        }
      }
    cout << tot << endl;
  }

  return 0;
}
