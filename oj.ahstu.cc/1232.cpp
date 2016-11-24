#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
  for (int n; cin >> n;) {
    vector<int> scores(n);
    for (int i = 0; i < n; i++) cin >> scores[i];
    sort(scores.begin(), scores.end());
    float sum = 0;
    for (vector<int>::iterator it = scores.begin() + 1; it != scores.end() - 1;
         ++it)
      sum += *it;
    cout << setiosflags(ios::fixed) << setprecision(2)
         << sum / (scores.size() - 2) << endl;
  }
  return 0;
}