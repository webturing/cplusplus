#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char const *argv[]) {
  ifstream cin("D:\\data\\1112\\sample.in");
  int m, n;
  string s;
  getline(cin, s);
  // cout << s << endl;
  istringstream iss2(s);
  iss2 >> m;
  for (; m--;) {
    getline(cin, s);
    // cout << s << endl;
    istringstream iss(s);
    vector<int> v;
    for (int t; iss >> t; v.push_back(t))
      ;
    n = v.size();
    vector<int> w(n);
    int j = 0;
    for (int i = n - 1; i >= 0; i--)
      if (v[i] < v[0]) w[j++] = v[i];
    for (int i = 0; i < n; i++)
      if (v[i] == v[0]) w[j++] = v[i];
    for (int i = 0; i < n; i++)
      if (v[i] > v[0]) w[j++] = v[i];
    cout << w[0];
    for (int i = 1; i < n; i++) cout << " " << w[i];
    cout << endl;
  }
  return 0;
}
