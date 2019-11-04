
/**
Sample Input

4 1 2 3 4
5 1 2 3 4 5
0

Sample Output

10
15


http://acm.hdu.edu.cn/showproblem.php?pid=1092
*/
#include <iostream>
using namespace std;
int main() {
  int n, k;
  while (cin >> n) {
    if (n == 0) break;
    int s = 0;
    while (n--) {
      cin >> t;
      s += t;
    }
    cout << s << endl;
  }
  return 0;
}