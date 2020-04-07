#include <bits/stdc++.h>

using namespace std;

int main() {
  int a;
  char c;
  cin >> a >> c;
  int b = (a + 1) / 2;
  for (int i = 0; i < b; i++) {
    for (int j = 0; j < a; j++) {
      if (j == 0 || i == 0 || i == b - 1 || j == a - 1)
        cout << c;
      else
        cout << ' ';
    }
    cout << endl;
  }

  return 0;
}