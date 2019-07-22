#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main() {
  int x = 123, y = 45;
  ostringstream oss;
  cout << x << y << " " << y << x << endl;  // 12345  45123
  oss << x << y << " " << y << x;
  int a, b;
  istringstream iss(oss.str());
  iss >> a >> b;
  cout << "a=" << a << endl;
  cout << "b=" << b << endl;
  return 0;
}