
/**
Sample Input
1 5
10 20
0 0
Sample Output
6
30

http://acm.hdu.edu.cn/showproblem.php?pid=1091
*/
#include <iostream>
using namespace std;
int main() {
  int a, b;
  while (cin >> a >> b) {
    if (a == 0 && b == 0) break;
    cout << a + b << endl;
  }
  return 0;
}