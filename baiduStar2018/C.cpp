#include <bits/stdc++.h>
using namespace std;

char M[10000 + 50];
int main() {
  ifstream cin("C.txt");
  ios::sync_with_stdio(false);
  for (int n, k; cin >> n >> k;) {
    cin >> M;
    vector<pair<int, int>> v;
    for (int i = 0, j; i < n; i++) {
      while (i < n && M[i] == '0') ++i;
      for (j = i; j < n && M[j] == '1'; j++)
        ;
      v.push_back(make_pair(i, j - 1));
      i = j;
    }
    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
      return b.second - b.first < a.second - a.first;
    });
    int sum = 0;
    k++;
    for (int i = 0; i < k / 2; i++) {
      sum += v[i].second - v[i].first + 1;
      if (v[i].second == n - 1 || v[i].first == 0) k++;
    }
    cout << sum << endl;
  }
  return 0;
}