#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>
using namespace std;
int main() {
  int y;
  cin >> y;
  if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
    cout << "yes" << endl;
  else
    cout << "no" << endl;
  return 0;
}
