#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  float total, sum = 0;
  int n;
  cin >> total >> n;
  vector<float> v(n);
  for (int i = 0; i < n; i++) cin >> v[i], sum += v[i];
  if (sum != total)
    cout << "Wrong Answer~" << endl;
  else {
    sort(v.begin(), v.end());
    if (v[n - 2] == v[n - 1])
      cout << "Not Very Good~" << endl;
    else
      cout << "Wonderful~" << endl;
  }
  return 0;
}
