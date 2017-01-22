#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int T, n, x;
  for (cin >> T; T-- && cin >> n;) {
    int s = 0;
    for (; n-- && cin >> x; s = s ^ x)
      ;
    cout << s << endl;
  }

  return 0;
}