#include <bits/stdc++.h>
using namespace std;
// 2. 计算1—1000之间能同时被3和5整除的整数的和。
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * b / gcd(a, b); }
int sum(int start, int end, int r) {
  vector<int> v;
  for (auto i = start; i <= end; i++)
    if (i % r == 0) v.push_back(i);
  return accumulate(v.begin(), v.end(), 0);
}

int main(int argc, char const *argv[]) {
  int start = 1, end = 1000, p = 3, q = 5;
  cout << sum(start, end, lcm(p, q)) << endl;
  return 0;
}