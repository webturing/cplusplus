#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream cin("in.txt");
  int n;
  while (cin >> n) {
    if (n == 0) break;
    vector<double> S(n);
    for (int i = 0; i < n; i++) cin >> S[i];
    double m = accumulate(S.begin(), S.end(), 0);
    double sd = 0;
    for (int i = 0; i < n; i++) sd += (n * S[i] - m) * (n * S[i] - m);
    cout << fixed << setprecision(8) << sqrt(sd / n) / n << endl;
  }
  return 0;
}