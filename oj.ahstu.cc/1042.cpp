#include <iostream>
#include <iomanip>

using namespace std;

int fact(int n) { return n ? fact(n - 1) * n : 1; }

int main(int argc, char const *argv[]) {
  for (int N; cin >> N; cout << fact(N) << endl)
    ;
  return 0;
}
