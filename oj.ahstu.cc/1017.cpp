#include <iostream>
#include <string>
#include <iterator>

using namespace std;

int main(int argc, char const *argv[]) {
  string s;
  cin >> s;
  for (string::const_iterator it = s.begin(); it != s.end(); ++it) cout << *it;
  for (string::const_reverse_iterator it = s.rbegin(); it != s.rend(); ++it)
    cout << *it;
  cout << endl;
  return 0;
}