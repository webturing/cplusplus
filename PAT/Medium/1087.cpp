#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
  set<int> S;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    S.insert((i) / 2 + (i) / 3 + (i) / 5);
  }
  cout << S.size();
  return 0;
}