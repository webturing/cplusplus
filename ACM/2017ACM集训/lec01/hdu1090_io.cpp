
/**
Sample Input
2
1 5
10 20

Sample Output

6
30

http://acm.hdu.edu.cn/showproblem.php?pid=1090
*/
#include <iostream>
using namespace std;
int main() {
  int cas, a, b;
  cin >> cas;
  while (cas--) {
    cin >> a >> b;
    cout << a + b << endl;
  }
  return 0;
}