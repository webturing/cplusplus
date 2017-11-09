#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  string RANK =
      "EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE"
      "DDDDDDDDDD"
      "CCCCCCCCCC"
      "BBBBBBBBBB"
      "AAAAAAAAAAA";
  for (int n; cin >> n;) {
    if (n < 0 || n > 100)
      cout << "Score is error!" << endl;
    else
      cout << RANK[n] << endl;
  }

  return 0;
}