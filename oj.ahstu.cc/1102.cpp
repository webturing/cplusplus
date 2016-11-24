#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[]) {
  for (int m, n; cin >> m >> n;) {
    int x = 0, y = 0;
    for (int i = m; i <= n; i++)
      if (i % 2)
        y += i * i * i;
      else
        x += i * i;
    cout << x << " " << y << endl;
  }
  return 0;
}
