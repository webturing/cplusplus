
#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>
using namespace std;
int main() {
  vector<double> v(3);
  cin >> v[0] >> v[1] >> v[2];
  double sum = std::accumulate(v.begin(), v.end(), 0.0);
  double mean = sum / v.size();  //均值
  cout << setiosflags(ios::fixed) << setprecision(3) << mean << endl;
  return 0;
}
