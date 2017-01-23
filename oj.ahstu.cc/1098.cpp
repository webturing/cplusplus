#include <iostream>
#include <vector>
using namespace std;
unsigned long long factorial(int n) {
  if (n <= 1) return 1LL;
  return factorial(n - 1) * n;
}
int main(int argc, char const *argv[]) {
  int n;
  string s;
  for (; cin >> n >> s;) {
    int m = s.length();
    vector<int> v(26, 0);
    for (string::const_iterator it = s.begin(); it != s.end(); ++it) {
      ++v[*it - 'a'];
    }
    unsigned long long total = factorial(m);
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
      total /= factorial(*it);
    }
    cout << total << endl;
  }

  return 0;
}