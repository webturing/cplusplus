
#include <iostream>
#include <vector>
using namespace std;
int main() {
  vector<int> v(1, 1);
  int n;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    auto sc = 0;
    for (auto& p : v) {
      p = p * i + sc;
      sc = p / 10;
      p %= 10;
    }
    while (sc) {
      v.push_back(sc % 10);
      sc /= 10;
    }
  }
  for (auto p = v.rbegin(); p != v.rend(); ++p) cout << *p;
  cout << endl;
  return 0;
}
