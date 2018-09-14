#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  vector<int> S(2, 0);
  while (t--) {
    string a, b;
    cin >> a >> b;
    if (a > b)
      S[0] += 3;
    else if (a < b)
      S[1] += 3;
    else
      S[0]++, S[1]++;
  }
  cout << S[0] << " " << S[1] << endl;

  return 0;
}