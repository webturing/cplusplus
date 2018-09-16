#include <bits/stdc++.h>
using namespace std;
int cmp(string ca, string cb) { return ca[1] - cb[1]; }
int bubbleSort(vector<string> &v) {
  int tot = 0;
  for (int i = 0, n = v.size(); i < n; i++) {
    bool isSorted = true;
    for (int j = n - 1; j > i; j--) {
      if (cmp(v[j], v[j - 1]) < 0) {
        isSorted = false;
        swap(v[j], v[j - 1]);
        ++tot;
      }
    }
    if (isSorted) break;
  }
  return tot;
}
int selectionSort(vector<string> &v) {
  int tot = 0;
  for (int i = 0, n = v.size(); i < n; i++) {
    int k = i;
    for (int j = i; j < n; j++) {
      if (cmp(v[j], v[k]) < 0) {
        k = j;
      }
    }
    if (k != i) {
      ++tot;
      swap(v[k], v[i]);
    }
  }
  return tot;
}
template <typename T>
void print(vector<T> &v) {
  cout << v[0];
  for (size_t i = 1; i < v.size(); i++) cout << " " << v[i];
  cout << endl;
}
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<string> v(n);
  for (auto &e : v) cin >> e;
  vector<string> w(v);
  bubbleSort(v);
  print(v);
  cout << "Stable" << endl;
  selectionSort(w);
  print(w);
  if (w == v)
    cout << "Stable" << endl;
  else
    cout << "Not stable" << endl;

  return 0;
}
