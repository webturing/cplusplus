#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
struct date {
  int y, m, d;
  bool operator<(const date &a) const {
    if (y != a.y) return y < a.y;
    if (m != a.m) return m < a.m;
    return d < a.d;
  }
};
int main(int argc, char const *argv[]) {
  vector<date> v;
  for (date d; ~scanf("%d/%d/%d", &d.m, &d.d, &d.y);) {
    v.push_back(d);
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++)
    printf("%02d/%02d/%4d\n", v[i].m, v[i].d, v[i].y);

  return 0;
}
