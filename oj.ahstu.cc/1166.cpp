#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

int main(int argc, char const *argv[]) {
  vector<int> v((istream_iterator<int>(cin)), (istream_iterator<int>()));
  vector<int> u(v);
  sort(u.begin(), u.end());
  cout << (u == v ? "YES" : "NO") << endl;
  return 0;
}
