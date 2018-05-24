
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  std::vector<double> v(3);
  cin >> v[0] >> v[1] >> v[2];
  sort(v.begin(), v.end());
  if (v[0] + v[1] <= v[2])
    cout << "not a triangle" << endl;
  else if (v[0] * v[0] + v[1] * v[1] == v[2] * v[2])
    cout << "yes" << endl;
  else
    cout << "no" << endl;
  return 0;
}
