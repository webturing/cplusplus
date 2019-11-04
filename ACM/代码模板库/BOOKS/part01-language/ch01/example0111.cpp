#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int a, b, n, m;
  cin >> n >> m;
  a = (4 * n - m) / 2;
  b = n - a;
  if (m % 2 == 0 && a >= 0 && b >= 0) {
    cout << a << " " << b << endl;
  } else {
    cout << "No answer" << endl;
  }
  return 0;
}
//鸡兔同笼