#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;
const int M = 100000000;
int k, w;
int m, n, s;

struct highNum {
  int num[27];
  highNum(int length = 1) {
    memset(num, 0, sizeof(num));
    num[0] = length;
  }
  highNum operator=(int b) {
    memset(num, 0, sizeof(num));
    num[0] = 1;
    num[1] = b;
    int ret = num[1] / M, iter = 1;
    while (ret != 0) {
      num[iter] %= M;
      num[++iter] += ret;
      ret = num[iter] / M;
    }
    while (num[num[0] + 1] != 0) ++num[0];
    return *this;
  }
  highNum operator+(highNum &b) const {
    highNum c = highNum(max(num[0], b.num[0]));
    for (int i = 1; i <= c.num[0]; ++i) {
      c.num[i] += num[i] + b.num[i];
      c.num[i + 1] += c.num[i] / M;
      c.num[i] %= M;
    }
    while (c.num[c.num[0] + 1] != 0) ++c.num[0];
    return c;
  }
};

ostream &operator<<(ostream &o, highNum &b) {
  o << b.num[b.num[0]];
  o.setf(ios::fixed);
  for (int i = b.num[0] - 1; i >= 1; --i) {
    o.width(8);
    o.fill('0');
    o << b.num[i];
  }
  return o;
}

highNum ans, f[600][514];

void init() {
  cin >> k >> w;
  s = (w + k) / k;
  m = (1 << (w % k)) - 1;
  n = (1 << k) - 1;
}

void work() {
  for (int i = 1; i <= n; ++i) f[1][i] = i;
  for (int i = 2; i <= s; ++i)
    for (int j = i; j <= n; ++j) f[i][j] = f[i - 1][j - 1] + f[i][j - 1];
  for (int i = 2; i < s; ++i) ans = ans + f[i][n];
  for (int i = 1; i <= m; ++i) ans = ans + f[s - 1][n - i];
  cout << ans;
}

int main() {
  init();
  work();
  return 0;
}
