#include <bits/stdc++.h>
using namespace std;
const int SENTINEL = numeric_limits<int>::max();
void merge(vector<int> &A, int left, int mid, int right, int &comp) {
  int n1 = mid - left;
  int n2 = right - mid;
  vector<int> L(n1 + 1, 0);
  vector<int> R(n2 + 1, 0);
  for (int i = 0; i < n1; i++)
    L[i] = A[left + i];
  for (int i = 0; i < n2; i++)
    R[i] = A[mid + i];
  L[n1] = R[n2] = SENTINEL;
  int i = 0, j = 0;
  for (int k = left; k <= right - 1; k++) {
    ++comp;
    if (L[i] <= R[j])
      A[k] = L[i++];
    else
      A[k] = R[j++];
  }
}
void merge_sort(vector<int> &A, int left, int right, int &comp) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    merge_sort(A, left, mid, comp);
    merge_sort(A, mid, right, comp);
    merge(A, left, mid, right, comp);
  }
}
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &e : v)
    cin >> e;
  int tot = 0;
  merge_sort(v, 0, v.size(), tot);
  cout << v[0];
  for (size_t i = 1; i < v.size(); i++) {
    cout << " " << v[i];
  }
  cout << endl;
  cout << tot << endl;
  return 0;
}
