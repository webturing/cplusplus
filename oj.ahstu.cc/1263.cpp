#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  for (unsigned n; cin >> n;) {
    vector<int> v;
    while (n) {
      v.push_back(n % 2);
      n /= 2;
    }
    n = 0;
    for (int i = 0; i < v.size(); i++) n = n * 2 + v[i];
    cout << n << endl;
  }

  return 0;
}
