#include <iostream>
using namespace std;
bool leap(int y) { return y % 4 == 0 && y % 100 != 0 || y % 400 == 0; }
int DAYS[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                   {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
struct date {
  int y, m, d;
  void inc() {
    if (d < 28) {
      d++;
      return;
    }
    switch (m) {
      case 1:
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
      case 12: {
        if (d < 31)
          d++;
        else if (m < 12)
          m++, d = 1;
        else
          y++, m = 1, d = 1;

      } break;
      case 4:
      case 6:
      case 9:
      case 11: {
        if (d < 30)
          d++;
        else if (m < 12)
          m++, d = 1;
        else
          y++, m = 1, d = 1;

      } break;
      case 2: {
        if (d < 28)
          d++;
        else if (leap(y) && d < 29)
          d++;
        else
          m++, d = 1;

      } break;
    }
  }
};
int main() {
  date d;
  while (cin >> d.y >> d.m >> d.d) {
    for (int i = 0; i < 10000; i++) d.inc();
    cout << d.y << "-" << d.m << "-" << d.d << endl;
  }

  return 0;
}
