#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
  int ah, am, as, bh, bm, bs, ch, cm, cs, sc;
  for (; cin >> ah >> am >> as >> bh >> bm >> bs;) {
    sc = 0;
    cs = as + bs + sc;
    sc = cs / 60;
    cs %= 60;
    cm = am + bm + sc;
    sc = cm / 60;
    cm %= 60;
    ch = (ah + bh + sc) % 24;
    cout << ch / 10 << ch % 10 << ":" << cm / 10 << cm % 10 << ":" << cs / 10
         << cs % 10 << endl;
  }
  return 0;
}