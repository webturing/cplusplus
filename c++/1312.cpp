#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  string s;
  cin >> s;
  for (auto p = s.rbegin(); p != s.rend(); ++p) {
    cout << *p;
  }
  cout << endl;

  return 0;
}