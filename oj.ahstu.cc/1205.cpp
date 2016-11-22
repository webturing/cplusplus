#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]) {
  char c[4];
  int n;
  for (cin >> n; n-- && cin >> s;)
    sort(c, c + 3), printf("%c %c %c\n", c[0], c[1], c[2]);
  return 0;
}
