#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  vector<int> fibs(30 + 2);
  fibs[1] = 0;
  fibs[2] = 1;
  for (unsigned i = 3; i < fibs.size(); i++)
    fibs[i] = fibs[i - 1] + fibs[i - 2];
  int n;
  cin >> n;
  cout << fibs[n] << endl;
  return 0;
}