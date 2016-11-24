#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
bool ok(string M) {
  for (int i = 0; i < M.length() / 2; i++)
    if (M[i] != M[M.length() - 1 - i]) return false;
  return true;
}
long long str2int(string M, int N) {
  long long ret = 0;
  for (int i = 0; i < M.length(); i++) ret = ret * N + M[i] - '0';
  return ret;
}
string int2str(long long M, int N) {
  vector<int> s;
  while (M) s.push_back(M % N), M /= N;
  char cs[1000] = {0};
  for (int i = 0; i < s.size(); i++) cs[i] = s[i] + '0';
  string ret(cs);

  return ret;
}
string rev(string M) {
  string ret = "";
  for (int i = M.length() - 1; i >= 0; i--) ret += M[i];
  return ret;
}
int main() {
  freopen("data.in", "r", stdin);
  string M;
  long long m;
  for (int N, step; cin >> N >> M;) {
    for (step = 0; !ok(M) && step <= 30; ++step) {
      int m = str2int(M, N);
      int rm = str2int(rev(M), N);
      M = int2str(m + rm, N);
    }
    if (ok(M))
      cout << "STEP=" << step << endl;
    else
      cout << "Impossible" << endl;
  }

  return 0;
}