#include <bits/stdc++.h>
using namespace std;
void print(vector<int> v) {
  for (size_t i = 0; i < v.size(); i++) {
    if (i) cout << " ";
    cout << v[i];
  }
  cout << endl;
}
int main() {
  int n;
  cin >> n;
  vector<int> a;
  for (int i = 1; i <= n; i++) a.push_back(i);
  do {
    print(a);
  } while (next_permutation(a.begin(), a.end()));
  return 0;
}