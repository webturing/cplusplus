
/**
Sample Input
2
3
4
Sample Output
2
2

Hint
In the first case, 3 * 3 * 3 = 27, so the leftmost digit is 2.
In the second case, 4 * 4 * 4 * 4 = 256, so the leftmost digit is 2.

http://acm.hdu.edu.cn/showproblem.php?pid=1060
*/
#include <iostream>
#include <cmath>
using namespace std;
int main() {
  int t, N;
 int y;
  double x = 0.0;
  cin >> t;
  while (t--) {
    cin >> N;
    x = fmod(N * log10((double)N), 1.0);
    cout << (int)pow(10, x) << endl;
  }
  return 0;
}