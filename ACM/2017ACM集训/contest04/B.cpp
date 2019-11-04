#include <iostream>
#include <set>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[]) {
  int a[6] = {100, 50, 10, 5, 2, 1};
  for (int n, t; cin >> n && n;) {
    int tot = 0;
    for (int t; n-- && cin >> t;)
      for (int i = 0; i < 6; i++) tot += t / a[i], t %= a[i];
    cout << tot << endl;
  }

  return 0;
}