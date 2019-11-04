#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int phi(int n) {
  int ret = n;
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) {
      ret = ret / i * (i - 1);  //先进行除法防止溢出(ret=ret*(1-1/p(i)))
      while (n % i == 0) n /= i;
    }
  if (n > 1) ret = ret / n * (n - 1);
  return ret;
}
int main() {
  int n;
  cin >> n;
  cout << phi(n) << endl;

  return 0;
}