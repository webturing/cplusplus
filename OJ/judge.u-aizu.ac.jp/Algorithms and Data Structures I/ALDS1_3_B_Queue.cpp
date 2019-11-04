#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  int n, q;
  cin >> n >> q;
  queue<pair<string, int> > Q;
  while (n--) {
    string name;
    int tim;
    cin >> name >> tim;
    pair<string, int> task = make_pair(name, tim);
    Q.push(task);
  }
  int T = 0, r = q;
  while (Q.size()) {
    pair<string, int> t = Q.front();
    Q.pop();
    if (t.second <= r) {
      T += t.second;
      cout << t.first << " " << T << endl;
    } else {
      t.second -= r;
      T += r;
      r = q;
      Q.push(t);
    }
  }
  return 0;
}
