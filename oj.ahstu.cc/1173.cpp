#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  for (int n; cin >> n;) {
    int k = 0, m = n;
    while (n) k++, n >>= 1;
    unsigned left = 1 << (k - 1), right = (1 << k);
    if (m - left <= right - m)
      cout << left << endl;
    else
      cout << left * 2 << endl;
  }
  return 0;
}