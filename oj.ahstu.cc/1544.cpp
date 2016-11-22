#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[]) {
  vector<int> v(2, 1);
  while (v.size() < 30) v.push_back(v[v.size() - 1] + v[v.size() - 2]);
  for (int i = 1; i < v.size(); i++) v[i] += v[i - 1];
  int m, n;
  for (cin >> m; m-- && cin >> n; cout << (n == 0 ? 0 : v[n - 1]) << endl)
    ;
  return 0;
}