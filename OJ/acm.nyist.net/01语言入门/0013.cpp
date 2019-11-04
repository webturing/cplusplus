#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v(21, 1);
  for (unsigned int i = 3; i < v.size(); i++) v[i] = v[i - 1] + v[i - 2];
  for (int n; cin >> n;)
    for (int m; n-- && cin >> m; cout << v[m] << endl)
      ;
  return 0;
}
