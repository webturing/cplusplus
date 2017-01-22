#include <iostream>
#include <stack>
using namespace std;
bool ok(string &t) {
  stack<char> s;
  for (string::const_iterator it = t.begin(); it != t.end(); ++it) {
    if (*it == '(' || *it == '[')
      s.push(*it);
    else if (*it == ']') {
      if (s.size() == 0 || s.top() != '[') return false;
      s.pop();
    } else if (*it == ')') {
      if (s.size() == 0 || s.top() != '(') return false;
      s.pop();
    }
  }
  return s.size() == 0;
}
int main(int argc, char const *argv[]) {
  int T;
  string w;
  for (cin >> T; T-- && cin >> w;) {
    cout << (ok(w) ? "Yes" : "No") << endl;
  }

  return 0;
}