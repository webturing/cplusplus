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

vector<int> add(const vector<int>& a, const vector<int>& b) {
  vector<int> c;
  int sc = 0, x, y;
  for (int i = 0; i < max(a.size(), b.size()); i++) {
    if (i >= a.size())
      x = 0;
    else
      x = a[i];
    if (i >= b.size())
      y = 0;
    else
      y = b[i];
    int temp = x + y + sc;
    sc = temp / 10;
    c.push_back(temp % 10);
  }
  if (sc) {
    c.push_back(sc % 10);
  }
  return c;
}
void bprint(const vector<int>& v) {
  copy(v.rbegin(), v.rend(), ostream_iterator<int>(cout, ""));
  cout << endl;
}
int main(int argc, char const* argv[]) {
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    v = add(v, fractorial(i));
  }
  bprint(v);
  return 0;
}
/*
4、阶乘和(sum)
【问题描述】
已知正整数 N（N<=100）,设 S=1!+2!+3!+...N!。其中"!"表示阶乘,即
N!=1*2*3*……*(N-1)*N，
如:3!=1*2*3=6。请编程实现：输入正整数 N,输出计算结果 S 的值。
【输入样例】
4
【输出样例】
33
*/