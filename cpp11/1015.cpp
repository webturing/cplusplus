
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
  string s;
  cin >> s;
  for (auto p : s) {
    cout << (char)(tolower(p));
  }
  cout << endl;
  return 0;
}
