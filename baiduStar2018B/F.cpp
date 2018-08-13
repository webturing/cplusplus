#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
typedef long long LL;

#define LOCAL

int main() {
#ifdef LOCAL
  ifstream cin("F.in");
  // ofstream cout("F.out");
  LL start = clock();
#endif
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int mx, my, n;
    cin >> mx >> my >> n;
    LL tot = 0;
    while (n--) {
      int x, y;
      cin >> x >> y;
      tot += min(min(mx - x, x), min(y, my - y));
    }
    cout << tot << endl;
  }
  return 0;
}