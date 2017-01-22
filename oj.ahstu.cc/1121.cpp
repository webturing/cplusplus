#include <iostream>
#include <set>
using namespace std;
int main() {
  for (int n; cin >> n;) {
    set<int> s;
    for (int i = 0; i < n; i++) {
      int t;
      cin >> t;
      s.insert(t);
    }
    cout << s.size() << endl;
    set<int>::iterator it = s.begin();
    cout << *it;
    for (++it; it != s.end(); ++it) cout << " " << *it;
    // cout << endl;
  }
  return 0;
}