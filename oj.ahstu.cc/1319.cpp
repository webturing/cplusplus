#include <iostream>
#include <set>
using namespace std;
set<char> f(const string& s) {
  set<char> ans;
  for (string::const_iterator it = s.begin(); it != s.end(); ++it) {
    ans.insert(*it);
  }
  return ans;
}
int main() {
  int n;
  cin >> n;
  for (string a, b; n-- && cin >> a >> b;)
    if (f(a) == f(b))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;

  return 0;
}