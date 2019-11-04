/**
Description
计算一个整数N的阶乘
Input
一个整数N, (0〈=N〈=12)
Output
整数N的阶乘.
Sample Input
5
Sample Output
120
*/

#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
int fact(int n) { return n == 0 ? 1 : fact(n - 1) * n; }
int main() {
  int n;
  while (cin >> n) cout << fact(n) << endl;
        return 0;

}

