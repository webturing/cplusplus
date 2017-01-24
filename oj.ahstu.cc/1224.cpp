#include <iostream>
using namespace std;
int a[100][100];
void rot1(int size) {
  int b[size][size];
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      b[size - 1 - j][i] = a[i][j];
    }
  }
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) a[i][j] = b[i][j];
}
void rot(int size, int count) {
  count % = 4;
  for (int i = 0; i < count; i++) rot1(size);
}
void disp(int size) {
  for (int i = 0; i < size; i++) {
    cout << a[i][0];
    for (int j = 1; j < size; j++) {
      cout << " " << a[i][j];
    }
    cout << endl;
  }
}
int main(int argc, char const *argv[]) {

  for (int size, count; cin >> size >> count;) {
    for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++) cin >> a[i][j];
    rot(size, count);
    disp(size);
  }
  return 0;
}