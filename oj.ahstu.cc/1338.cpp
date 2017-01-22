#include <iostream>
#include <fstream>
using namespace std;

int q = 0;
void derive(int n) {
  int i;
  if (n == 1) {
    q++;
    return;
  } else {
    for (i = 2; i <= n; i++) {
      if (n % i == 0) {
        // q++;
        derive(n / i);
      }
    }
  }
}
int main() {
  ifstream cin("d:\\data\\1338\\fact0.in");
  int n;
  cin >> n;
  derive(n);
  cout << q << endl;
  return 0;
}
