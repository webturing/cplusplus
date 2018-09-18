#include <bits/stdc++.h>
using namespace std;
string D = "0123456789ABCDEFGHIJ";
int main(int argc, char const *argv[]) {
  int n, r;
  cin >> n >> r;
  vector<int> R(1);
  int t = abs(r);
  while (t < n) {
        R.push_back(t*abs(r)));
  }

  return 0;
}