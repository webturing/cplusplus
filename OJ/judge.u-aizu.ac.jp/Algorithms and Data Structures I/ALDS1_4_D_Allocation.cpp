#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  // ifstream cin("in.txt");
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  vector<int> w(n);
  for (auto &e : w)
    cin >> e;
  int left = *max_element(w.begin(), w.end()),
      right = accumulate(w.begin(), w.end(), 0), p = right;
  while (left <= right) {
    int middle = (left + right) / 2;
    bool flag = true;
    int cnt = 1, cur = middle;
    for (auto e : w) {
      if (e <= cur) {
        cur -= e;
      } else {
        cnt++;
        cur = middle - e;
      }
      if (cnt > k) {
        flag = true;
        break;
      }
    }
    if (cnt > k) {
      flag = false;
    }
    if (flag) {
      p = min(middle, p);
      right = middle - 1;
    } else {
      left = middle + 1;
    }
    // cout << flag << " " << middle << " [" << left << "," << right << "]"
    //     << endl;
  }
  cout << p << endl;
  return 0;
}
