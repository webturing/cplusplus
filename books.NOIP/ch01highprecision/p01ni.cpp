#include <bits/stdc++.h>
using namespace std;
vector<int> fractorial(int n) {
  vector<int> v(1, 1);
  for (int i = 2; i <= n; i++) {
    int sc = 0;
    for (int j = 0; j < v.size(); j++) {
      v[j] = v[j] * i + sc;
      sc = v[j] / 10;
      v[j] %= 10;
    }
    while (sc > 0) {
      v.push_back(sc % 10);
      sc /= 10;
    }
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
  bprint(fractorial(n));

  return 0;
}
/*
1、求 N！的值(ni)
【问题描述】
 用高精度方法，求 N！的精确值(N 以一般整数输入)。
【输入样例】
 10
【输出样例】
 3628800
*/