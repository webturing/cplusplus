
/**
Sample Input
2
4 1 2 3 4
5 1 2 3 4 5


Sample Output

10
15


http://acm.hdu.edu.cn/showproblem.php?pid=1093
*/
#include <iostream>
using namespace std;
int main() {
  int cas, n, k;
  cin >> cas;
  while (cas--) {
    cin >> n;
    int s = 0;
    while (n--) {
      cin >> k;
      s += k;
    }
    cout << s << endl;
  }
  return 0;
}