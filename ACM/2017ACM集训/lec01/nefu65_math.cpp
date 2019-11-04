
/**
Sample Input
1
3
32000
1000000
Sample Output
1
1
130271
5565709

http://acm.nefu.edu.cn/JudgeOnline/problemShow.php?problem_id=65
*/
#include <iostream>
#include <cmath>
using namespace std;
int main() {
  int N, i;
  double sum;
  while (cin >> N) {
    sum = 0;
    for (i = 2; i <= N; i++) sum += log10(i);
    cout << (int)sum + 1 << endl;
  }
  return 0;
}