#include <bits/stdc++.h>
using namespace std;
bool primer(int n) {
  if (n == 2) return true;
  if (n < 2 || n % 2 == 0) return false;
  for (int c = 3; c * c <= n; c += 2)
    if (n % c == 0) return false;
  return true;
}
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  int cnt = 0;
  while (n--) {
    int t;
    cin >> t;
    cnt += primer(t);
  }
  cout << cnt << endl;
  return 0;
}
