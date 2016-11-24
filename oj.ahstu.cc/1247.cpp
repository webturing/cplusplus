#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  for (unsigned n; cin >> n;) cout << n *(n + 1) / 2 << endl;
  return 0;
}