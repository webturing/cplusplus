#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int n = 120;
  int a = n / 100;
  int b = (n % 100) / 10;
  int c = n % 10;
  cout << c << b << a << endl;
  return 0;
}