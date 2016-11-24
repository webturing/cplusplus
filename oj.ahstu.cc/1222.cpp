#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[]) {
  ifstream cin("d:\\data\\1222\\sample.in");
  int size, inc;
  for (; cin >> size >> inc;) {
    vector<int> v(size);
    for (int i = 0; i < size; i++) cin >> v[i];
    if (inc)
      sort(v.begin(), v.end(), greater<int>());
    else
      sort(v.begin(), v.end(), less<int>());
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
      cout << *it << endl;
  }
  return 0;
}