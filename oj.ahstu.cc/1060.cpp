#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int cmp(const int& a, const int& b) { return abs(b) < abs(a); }
int main() {

  for (int n; cin >> n && n;) {
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end(), cmp);
    cout << v[0];
    for (int i = 1; i < n; i++) cout << ' ' << v[i];
    cout << endl;
  }
  return 0;
}
