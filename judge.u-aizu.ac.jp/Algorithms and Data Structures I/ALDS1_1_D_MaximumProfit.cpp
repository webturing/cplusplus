#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<int> R(n);
  for (auto &i : R) cin >> i;
  int maxv = -1;
  for (int j = 1; j < n; j++)
    for (int i = 0; i < j; i++) maxv = max(maxv, R[j] - R[i]);
  cout << maxv << endl;
  return 0;
}
