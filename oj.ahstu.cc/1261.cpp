#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
  freopen("data.in", "r", stdin);
  vector<bool> prime(1000001, true);
  prime[0] = prime[1] = false;
  for (int i = 2; i * i < prime.size(); i++)
    if (prime[i])
      for (int j = i * i; j < prime.size(); j += i) prime[j] = 0;
  for (int n; cin >> n;) {
    int tot = 0;
    if (n > 2) ++tot;
    for (int m = 3; m + 2 <= n; m += 2)
      if (prime[m] && prime[m + 2]) ++tot;
    cout << tot << endl;
  }

  return 0;
}