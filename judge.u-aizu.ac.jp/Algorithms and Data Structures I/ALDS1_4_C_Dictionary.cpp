#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  map<string, bool> M;
  while (n--) {
    string op, e;
    cin >> op >> e;
    if (op == "insert") {
      M[e] = true;
    } else if (op == "find") {
      if (M[e])
        cout << "yes" << endl;
      else
        cout << "no" << endl;
    }
  }
  return 0;
}
