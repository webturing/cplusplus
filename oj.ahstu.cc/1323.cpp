#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
struct Student {
  string name;
  int year, month, day;
  bool operator<(const Student& s) const {
    if (this->year != s.year) return this->year < s.year;
    if (this->month != s.month) return this->month < s.month;
    return this->day < s.day;
  }
};
int main() {
  // ifstream cin("D:\\data\\1323\\sample.in");
  int n;
  cin >> n;
  vector<Student> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i].name >> v[i].year >> v[i].month >> v[i].day;
  sort(v.begin(), v.end());
  for (vector<Student>::iterator it = v.begin(); it != v.end(); ++it)
    cout << it->name << endl;
  return 0;
}