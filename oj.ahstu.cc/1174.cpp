#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
struct A {
  int start, end;
  bool operator<(const A& a) const { return this->end < a.end; }
};
int main() {
  ifstream cin("d:\\data\\1174\\sample.in");
  for (int n; cin >> n;) {
    vector<A> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].start >> v[i].end;
    sort(v.begin(), v.end());
    int count = 0;
    int start = 0;
    for (int i = 0; i < n; i++) {
      if (v[i].start >= start) {
        ++count;
        start = v[i].end;
      }
    }
    cout << count << endl;
  }
  return 0;
}