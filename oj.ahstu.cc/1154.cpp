#include <string>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
  for (string s; cin >> s;) {
    for (int i = 0; i < s.length(); i++) cout << (s[i] == '0');
    cout << endl;
  }
  return 0;
}