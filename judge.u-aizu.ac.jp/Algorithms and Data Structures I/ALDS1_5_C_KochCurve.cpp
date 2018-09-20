#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
inline double f(double x) {
  if (abs(x) < 1E-7)
    return 0;
  return x;
}
void koch(vector<pair<double, double> > &k, int n) {
  if (n == 0)
    return;
  vector<pair<double, double> > temp;
  temp.push_back(k[0]);
  double angel = 0;
  for (size_t i = 1; i < k.size(); i++) {
    auto v =
        make_pair(k[i].first - k[i - 1].first, k[i].second - k[i - 1].second);
    angel = atan(v.second / v.first);
    auto a =
        make_pair(k[i - 1].first + hypot(v.first, v.second) / 3 * cos(angel),
                  k[i - 1].second + hypot(v.first, v.second) / 3 * sin(angel));
    angel += pi / 3;
    auto b = make_pair(a.first + hypot(v.first, v.second) / 3 * cos(angel),
                       a.second + hypot(v.first, v.second) / 3 * sin(angel));
    angel -= 2 * pi / 3;
    auto c = make_pair(b.first + hypot(v.first, v.second) / 3 * cos(angel),
                       b.second + hypot(v.first, v.second) / 3 * sin(angel));

    temp.push_back(a);
    temp.push_back(b);
    temp.push_back(c);
    temp.push_back(k[i]);
  }
  k.resize(temp.size());
  copy(temp.begin(), temp.end(), k.begin());
  koch(k, n - 1);
}
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);

  vector<pair<double, double> > K{ make_pair(0, 0), make_pair(100.0, 0) };
  int n;
  cin >> n;
  koch(K, n);
  for (pair<double, double> p : K) {
    cout << fixed << setprecision(8) << f(p.first) << " " << f(p.second)
         << endl;
  }
  return 0;
}
