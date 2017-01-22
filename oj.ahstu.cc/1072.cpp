#include <iostream>
using namespace std;
long long dp[21];
long long f(int n) {
  if (dp[n]) return dp[n];
  if (n <= 3) return dp[n] = n - 1;
  return dp[n] = (n - 1) * (f(n - 1) + f(n - 2));
}
int main(int argc, char const *argv[]) {
  for (int n; cin >> n; cout << f(n) << endl)
    ;
  return 0;
}
