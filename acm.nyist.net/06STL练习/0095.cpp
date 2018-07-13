#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
typedef long long LL;
#define LOCAL

int main(int argc, char const *argv[]) {
  std::ios::sync_with_stdio(false);
#ifdef LOCAL
  ifstream cin("input.txt");
  ofstream cout("output.txt");
  assert(cin);
  LL start = clock();
#endif
  int n, m;
  for (cin >> n; n-- && cin >> m;) {
    vector<int> v(m);
    for (auto &e : v)
      cin >> e;
    sort(v.begin(), v.end());
    set<int> s(v.begin(), v.end());
    int maxV = 0, mElement = v[0];
    for (auto e : s) {
      int cur = upper_bound(v.begin(), v.end(), e) -
                lower_bound(v.begin(), v.end(), e);
      if (cur > maxV) {
        maxV = cur;
        mElement = e;
      }
    }
    cout << mElement << " " << maxV << endl;
  }

#ifdef LOCAL
  LL end = clock();
  printf("%.3f\n", (double)(end - start) / CLOCKS_PER_SEC);
#endif
  return 0;
}
