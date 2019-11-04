#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string today("2014/09/06");
  vector<pair<string, string>> V(N);
  for (auto &v : V) {
    cin >> v.first >> v.second;
  }
  sort(V.begin(), V.end(),
       [today](pair<string, string> a, vector<string, string> b) {

       });
  return 0;
}