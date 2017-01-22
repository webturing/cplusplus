#include <iostream>
#include <string>
#include <deque>
#include <vector>
using namespace std;

int main() {

  int type;
  string tel;
  vector<deque<string> > v;
  for (int i = 0; i < 3; i++) {
    deque<string> tel(10, "0");
    v.push_back(tel);
  }
  for (; cin >> type >> tel;) {
    v[type].push_front(tel);
  }
  for (int i = 0; i < 10; i++) {
    cout << v[0][i] << " " << v[1][i] << " " << v[2][i] << endl;
  }
  return 0;
}