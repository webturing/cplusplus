#include <bits/stdc++.h>
using namespace std;
struct Item {
  int value;
  int weight;
  char type;
  long long date;
  string name;
  bool operator<(const Item& other) const {
    if (value != other.value) return value < other.value;
    if (weight != other.weight) return weight < other.weight;
    if (type != other.type) return type < other.type;
    if (date != other.date) return date < other.date;
    if (name != other.name) return name < other.name;
    return false;
  }
};
int main() {
  int n;
  cin >> n;
  vector<Item> v(n);
  for (auto& p : v) cin >> p.value >> p.weight >> p.type >> p.date >> p.name;
  sort(v.begin(), v.end());
  for (auto p : v)
    cout << p.value << " " << p.weight << " " << p.type << " " << p.date << " "
         << p.name << endl;
  return 0;
}