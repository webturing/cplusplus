#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<vector<int> > cards(4, vector<int>(14, 1));
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string kind;
    int digit;
    cin >> kind >> digit;
    if (kind == "S")
      --cards[0][digit];
    if (kind == "H")
      --cards[1][digit];
    if (kind == "C")
      --cards[2][digit];
    if (kind == "D")
      --cards[3][digit];
  }
  string kinds("SHCD");
  for (int k = 0; k < 4; k++)
    for (int i = 1; i <= 13; i++) {
      if (cards[k][i])
        cout << kinds[k] << " " << i << endl;
    }
  return 0;
}