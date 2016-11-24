#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  string s;
  cin >> s;
  for (string::const_reverse_iterator it = s.rbegin(); it != s.rend(); ++it)
    cout << *it;
  cout << endl;
  return 0;
}
