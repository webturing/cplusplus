#include <iostream>
#include <cmath>
using namespace std;
int a[100][100];
int main(int argc, char const *argv[]) {
  for (int n; cin >> n;) {
    int size = 2 * n + 1;
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        int dist = max(abs(i - n), abs(j - n));
        a[i][j] = dist;
      }
    }
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        cout << " " << a[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}