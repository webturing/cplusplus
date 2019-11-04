
/**
Sample Input

4 1 2 3 4
5 1 2 3 4 5


Sample Output

10
15


http://acm.hdu.edu.cn/showproblem.php?pid=1094
*/
#include <iostream>
using namespace std;
int main() {
  int n, k;
  while (cin >> n) {
    int s = 0;
    while (n--) {
      cin >> k;
      s += k;
    }
    cout << s << endl;
  }
  return 0;
}