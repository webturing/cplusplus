#include <bits/stdc++.h>
using namespace std;

int main() {
  int r, c;
  cin >> r >> c;
  vector<vector<int> > v(r + 1, vector<int>(c + 1, 0));
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      cin >> v[i][j];
  for (int i = 0; i < r; i++) {
    v[i][c] = accumulate(v[i].begin(), v[i].end() - 1, 0);
  }
  for (int j = 0; j < c + 1; j++) {
    for (int i = 0; i < r; i++)
      v[r][j] += v[i][j];
  }
  for (int i = 0; i <= r; i++) {
    for (int j = 0; j <= c; j++) {
      cout << v[i][j];
      if (j < c)
        cout << " ";
    }
    cout << endl;
  }
  return 0;
}