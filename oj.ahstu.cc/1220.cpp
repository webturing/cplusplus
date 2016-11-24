#include <iostream>
#include <set>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[]) {
  ifstream cin("d:\\data\\1220\\sample.in");
  set<int> st;
  int n, m;
  for (cin >> m; m-- && cin >> n; st.insert(n))
    ;
  for (set<int>::iterator it = st.begin(); it != st.end(); ++it)
    cout << *it << endl;

  return 0;
}