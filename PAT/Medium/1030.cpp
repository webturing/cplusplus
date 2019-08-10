#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll n, p;
  cin >> n >> p;
  vector<ll> v(n);
  for (auto &e : v) cin >> e;
  sort(v.begin(), v.end());
  ll Max = 1;
  for (int i = 0; i < n; i++) {
    ll e = v[i] * p;
    ll j = upper_bound(v.begin(), v.end(), e) - v.begin();
    Max = max(j - i, Max);
  }
  cout << Max << endl;
  return 0;
}