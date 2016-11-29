#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
  ifstream cin("d:\\data\\1257\\sample.in");
  for (string A, B, C; cin >> A >> B >> C;) {
    string::const_reverse_iterator ia = A.rbegin();
    string::const_reverse_iterator ib = B.rbegin();
    string::const_reverse_iterator ic = C.rbegin();
    if ((*ia - '0' + *ib - '0') % 10 == (*ic - '0'))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}