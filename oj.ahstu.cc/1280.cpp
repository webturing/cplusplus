
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
  vector<string> v(2);
  v[0] = "yes";
  v[1] = "no";
  int n;
  cin >> n;
  cout << v[n & 1] << endl;
  return 0;
}
