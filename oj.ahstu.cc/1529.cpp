#include <iostream>
using namespace std;
int main() {
  string v;
  for (int k, cnt; cin >> v >> k;) {
    for (int j = 0; k && j < v.length() - 1; j++) {
      int maxpos = j;
      for (int i = j + 1; i <= j + k && i < v.length(); i++)
        if (v[i] > v[maxpos]) maxpos = i;
      if (maxpos != j) {
        char t = v[maxpos];
        for (int i = maxpos - 1; i >= j; i--) v[i + 1] = v[i], k--;
        v[j] = t;
      }
    }
    cout << v << endl;
  }
  return 0;
}