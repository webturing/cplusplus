#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

struct Point {
  int x, y;
  bool operator<(const Point &point) const;
  friend ostream &operator<<(ostream &os, const Point &point);
  friend istream &operator>>(istream &is, Point &point);
};

istream &operator>>(istream &is, Point &point) {
  is >> point.x >> point.y;
  return is;
}

bool Point::operator<(const Point &point) const {
  if (this->x - point.x) return this->x < point.y;
  return this->y < point.y;
}

ostream &operator<<(ostream &os, const Point &point) {
  os << "(" << point.x << "," << point.y << ")";
  return os;
}

int main(void) {
  vector<Point> num;
  copy(istream_iterator<Point>(cin), istream_iterator<Point>(),
       back_insert_iterator<vector<Point> >(num));
  sort(num.begin(), num.end());
  copy(num.begin(), num.end(), ostream_iterator<Point>(cout, " "));
  return 0;
}
