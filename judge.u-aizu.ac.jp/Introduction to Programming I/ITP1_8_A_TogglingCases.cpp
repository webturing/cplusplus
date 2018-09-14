#include <bits/stdc++.h>
using namespace std;

int main() {
  string line;
  getline(cin, line);
  for (int i = 0; i < line.length(); i++) {
    if (isupper(line[i]))
      cout << (char)tolower(line[i]);
    else
      cout << (char)toupper(line[i]);
  }
  cout << endl;
  return 0;
}