#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[]) {
  for (int k, n; cin >> k >> n; k++) {
    int m = log(n) / log(k) + 5;
    vector<int> v(m, 1);
    for (int i = 1; i < m; i++) v[i] = v[i - 1] * k;
    set<int> pq;
    // int count = 0;
    for (int i = 0; i < (1 << m); i++) {
      int r[1000] = {0}, ci = i, j;
      int tot = 0;
      for (j = 0; j < m; j++) {
        r[j] = i % 2;
        if (r[j]) tot += v[j];
        i /= 2;
      }
      i = ci;
      pq.insert(tot);
    }
    set<int>::iterator it = pq.begin();
    for (int i = 0; i < n; i++) ++it;
    cout << *it << endl;
  }
  return 0;
}