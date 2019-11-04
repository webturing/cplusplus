#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  for (int i = 34; i * i <= 9999; i++) {
    int a = i * i / 100;
    int b = i * i % 100;
    if (a % 11 == 0 && b % 11 == 0) {
      cout << i *i << endl;
    }
  }
  return 0;
}