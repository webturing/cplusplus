#include <bits/stdc++.h>
using namespace std;
const int PRECISION = 20;
vector<int> divide(int a, int b) {
  vector<int> v;
  while (v.size() <= PRECISION) {
    v.push_back(a * 10 / b);
    a = (10 * a) % b;
    if (a == 0) break;
  }
  if (v.size() > PRECISION) {
    int sc = *v.rbegin() >= 5;
    while (sc > 0) {
      for (int i = v.size() - 2; i >= 0; i--) {
        v[i] = v[i] + sc;
        sc = v[i] / 10;
        v[i] %= 10;
        if (sc == 0) break;
      }
    }
    v.erase(v.end() - 1);
  }
  return v;
}
void bprint(const vector<int>& v) {
  copy(v.rbegin(), v.rend(), ostream_iterator<int>(cout, ""));
  cout << endl;
}
int main() {
  int a, b;
  cin >> a >> b;
  cout << a / b << ".";
  a %= b;
  bprint(divide(a, b));
  return 0;
}
/*
2、求 A/B 高精度值(ab)
【问题描述】
 计算 A/B 的精确值，设 A，B 是以一般整数输入，计算结果精确到小数后 20 位（若不足
20 位，末尾不
用补 0）。
【输入样例 1】
 4 3
【输出样例 1】
4/3=1.33333333333333333333
【输入样例 2】
 6 5
【输出样例 2】
6/5=1.2
*/