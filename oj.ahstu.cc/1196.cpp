#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main() {

  for (int n, m, k; cin >> n >> m >> k;) {
    vector<int> v(n);
    for (int i = 1; i <= n; i++) v.push_back(i);
    vector<int>::iterator it = v.begin();
    for (int i = 1; v.size() > k; i++) {
      ++it;
      if (it == v.end()) it == v.begin();

      if (i % m == 0) v.erase(it);
      copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
      cout << endl;
    }
    for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
    cout << endl;
  }

  return 0;
}
