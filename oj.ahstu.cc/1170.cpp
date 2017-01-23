#include <iostream>
#include <map>
using namespace std;
struct ploy {
  int m;
  map<int, int> mp;
  void input() {
    for (int i = 0; i < m; i++) {
      int coef, index;
      cin >> coef >> index;
      mp[index] = coef;
    }
  }
  void add(ploy &that) {
    this->m = this->m > that.m ? this->m : that.m;
    for (int i = 0; i <= m; i++) mp[i] += that.mp[i];
  }
  void disp() {
    for (int i = m; i >= 0; i--)
      if (mp[i]) cout << mp[i] << " " << i << endl;
  }
};

int main(int argc, char const *argv[]) {
  for (ploy a, b; cin >> a.m >> b.m;) {
    a.input();
    b.input();
    a.add(b);
    a.disp();
  }
  return 0;
}