#include <bits/stdc++.h>
using namespace std;
vector<int> add(vector<int>& v, int a) {
  int sc = 0;
  for (int i = 0; i < v.size(); i++) {
    v[i] = a % 10 + v[i] + sc;
    sc = v[i] / 10;
    v[i] %= 10;
    a /= 10;
  }
  while (sc) {
    v.push_back(sc % 10);
    sc /= 10;
  }
  return v;
}
void bprint(const vector<int>& v) {
  copy(v.rbegin(), v.rend(), ostream_iterator<int>(cout, ""));
  cout << endl;
}
int main() {
  int n;
  cin >> n;
  vector<int> v(1, 0);
  for (int i = 1; i <= n; i++) {
    add(v, i);
  }
  bprint(v);
  return 0;
}
/*
3、求 n 累加和(ja)
【问题描述】
用高精度方法，求 s=1+2+3+……+n 的精确值(n 以一般整数输入)。
【输入样例】
 10
【输出样例】
 55
*/
