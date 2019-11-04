#include <iostream>
using namespace std;
/**
Sample Input
3
4 1 2 3 4
5 1 2 3 4 5
3 1 2 3
Sample Output (one blank between case)
10

15

6

http://acm.hdu.edu.cn/showproblem.php?pid=1096
*/
int main() {
  int cas, n, k;
  cin >> cas;
  for (i = 0; i < cas; i++) {
    if (i) cout << endl;
    int s = 0;
    cin >> n;
    while (n--) {
      cin >> k;
      s += k;
    }
    cout << k << endl;
  }
  return 0;
}