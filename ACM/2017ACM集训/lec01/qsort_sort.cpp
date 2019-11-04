#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
int cmp(const void* a, const void* b) { return *(int*)a - *(int*)b; }
int main() {
  int data[10];
  for (int i = 0; i < 5; i++) cin >> data[i];
  qsort(data, 5, sizeof(data[0]), cmp);
  for (int i = 0; i < 5; i++) cout << a[i] << endl;
  return 0;
}
