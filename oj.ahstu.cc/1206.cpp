
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool prime(int n) {
  if (n <= 1) return false;
  for (auto i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
int main() {
  int m, n;
  for (cin >> m; m-- && cin >> n;) {
    vector<int> v(n);
    for (auto& p : v) cin >> p;
    auto sum = 0;
    for (auto p : v)
      if (prime(p)) sum += p;
    cout << sum << endl;
  }

  return 0;
}
