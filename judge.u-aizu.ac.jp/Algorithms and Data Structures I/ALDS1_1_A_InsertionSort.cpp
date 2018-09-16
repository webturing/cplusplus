#include <iostream>
using namespace std;
const int N = 100;
int a[N];
void output_result(int a[], int n) {
  for (int i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << a[i];
  }
  cout << endl;
}
void insertion_sort(int a[], int n) {
  for (int i = 1; i < n; i++) {
    int key = a[i];
    /* insert A[i] into the sorted sequence A[0,...,j-1] */
    int j = i - 1;
    while (j >= 0 && a[j] > key) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = key;
    output_result(a, n);
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  output_result(a, n);
  insertion_sort(a, n);
  return 0;
}