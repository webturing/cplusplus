#include <iostream>
#include <set>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[]) {
  ifstream cin("d:\\data\\1141\\sample.in");
  for (int n, t; cin >> n && n;) {
    set<int> st;
    for (int i = 0; i < n; i++) {
      cin >> t;
      st.insert(t);
    }
    cout << st.size() << endl;
    set<int>::iterator it = st.begin();
    cout << *it;
    for (++it; it != st.end(); ++it) {
      cout << " " << *it;
    }
    cout << endl << endl;
  }
  return 0;
}