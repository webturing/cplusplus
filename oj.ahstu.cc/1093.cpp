#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
int main() {
  for (string line; getline(cin, line);) {
    istringstream sin(line);
    int max = -0xffffff;
    for (int n; sin >> n;)
      if (n > max) max = n;
    cout << max << endl;
  }
  return 0;
}
