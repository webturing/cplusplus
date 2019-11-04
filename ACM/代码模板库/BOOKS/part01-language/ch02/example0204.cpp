#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  // int n;//bugs
  long long n;
  cin >> n;
  int cnt = 0;
  while (n > 1) {
    if (n % 2 == 0) {
      n /= 2;
    } else {
      n = 3 * n + 1;
    }
    ++cnt;
  }
  cout << cnt << endl;
  return 0;
}