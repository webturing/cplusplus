
#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>
using namespace std;
int main() {
  for (string s; cin >> s;) {
    for (auto p = s.rbegin(); p != s.rend(); ++p) cout << *p;
    cout << endl;
  }
  return 0;
}
