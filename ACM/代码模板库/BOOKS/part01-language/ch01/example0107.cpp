#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int n = 120;
  int a = n / 100;
  int b = (n % 100) / 10;
  int c = n % 10;
  cout << 100 * c + 10 * b + a << endl;
  cout << setw(3) << setfill('0') << 100 * c + 10 * b + a << endl;
  return 0;
}