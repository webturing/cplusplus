#include <bits/stdc++.h>
using namespace std;
void bprint(const vector<int>& v) {
  copy(v.rbegin(), v.rend(), ostream_iterator<int>(cout, ""));
  cout << endl;
}
vector<int> mul(const vector<int>& a, const vector<int>& b) {
  vector<int> c(a.size() + b.size(), 0);
  int sc = 0, i, j;
  for (i = 0; i < a.size(); i++) {
    for (j = 0; j < b.size(); j++) {
      int temp = c[i + j] + a[i] * b[j] + sc;
      sc = temp / 10;
      c[i + j] = temp % 10;
    }
    if (sc > 0) {
      if (i + j >= c.size()) {
        c.push_back(sc);
        sc /= 10;
      } else {
        c[i + j] += sc;
        sc = c[i + j] / 10;
        c[i + j] %= 10;
      }
    }
  }
  if (*(c.end() - 1) == 0) c.erase(c.end() - 1);
  return c;
}
int main(int argc, char const* argv[]) {
  string a, b;
  cin >> a >> b;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  vector<int> va(a.size());
  for (int i = a.size() - 1; i >= 0; i--) va[i] = a[i] - '0';

  vector<int> vb(b.size());
  for (int i = b.size() - 1; i >= 0; i--) vb[i] = b[i] - '0';
  bprint(va);
  bprint(vb);
  bprint(mul(va, vb));
  return 0;
}
/*
5、高精度求积(multiply)
【问题描述】
输入两个高精度正整数 M 和 N（M 和 N 均小于 100 位）。
【问题求解】
求这两个高精度数的积。
【输入样例】
36
3
【输出样例】
108
*/