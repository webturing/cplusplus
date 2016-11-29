#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
  ifstream cin("d:\\data\\1294\\sample.in");
  for (int n; cin >> n;) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int m;
    cin >> m;
    int count = 0;
    for (int i = 0; i < n; i++)
      if (a[i] < m) ++count;
    cout << count << endl;
  }
  return 0;
}