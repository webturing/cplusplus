#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <cctype>
using namespace std;

int main(int argc, char const *argv[]) {
  ifstream cin("d:\\data\\1211\\sample.in");
  int M, n;
  for (cin >> M; M-- && cin >> n;) {
    for (int i = 31; i >= 0; i--) cout << ((n >> i) & 1);
    cout << endl;
  }
  return 0;
}