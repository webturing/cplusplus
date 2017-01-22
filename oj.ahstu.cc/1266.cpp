#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  for (int a, b, c; cin >> a >> b >> c;) {
    if (a == -1 && b == -1 && c == -1) break;
    bool find = false;
    if (!find && a <= 168) {
      cout << "CRASH " << a << endl;
      find = true;
    }
    if (!find && b <= 168) {
      cout << "CRASH " << b << endl;
      find = true;
    }
    if (!find && c <= 168) {
      cout << "CRASH " << c << endl;
      find = true;
    }
    if (!find) cout << "NO CRASH" << endl;
  }
  return 0;
}
