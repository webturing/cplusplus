#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  for (int t; cin >> t;)
    for (unsigned n, no = 0; t-- && cin >> n; ++no) {
      bitset<32> b(n);
      // cout << b << endl;
      int j;
      for (j = 0; j < 32; j++)
        if (b[j])
          break;
      cout << "Case #" << no + 1 << ": " << (1 << j) << endl;
    }
  return 0;
}