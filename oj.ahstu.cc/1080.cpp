#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <cctype>
using namespace std;

int main(int argc, char const *argv[]) {
  ifstream cin("d:\\data\\1080\\test0.in");
  unsigned n, tot = 0;
  for (; cin >> n;) {
    bool flag = true;
    for (int i = 0; i < 16; i++)
      if (((n >> i) & 1) != ((n >> (31 - i)) & 1)) {
        flag = false;
        break;
      }
    if (flag) ++tot;
  }
  cout << tot << endl;
  return 0;
}