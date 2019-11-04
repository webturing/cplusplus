#include <bits/stdc++.h>

using namespace std;

int bubbleSort(vector<int> &v) {
  int tot = 0;
  for (int i = 0, n = v.size(); i < n; i++) {
    bool isSorted = true;
    for (int j = n - 1; j > i; j--) {
      if (v[j] < v[j - 1]) {
        isSorted = false;
        swap(v[j], v[j - 1]);
        ++tot;
      }
    }
    if (isSorted) break;
  }
  return tot;
}

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int &i : v) cin >> i;
  int t = bubbleSort(v);
  cout << v[0];
  for (int i = 1; i < n; i++) {
    cout << " " << v[i];
  }
  cout << endl << t << endl;
  return 0;
}
