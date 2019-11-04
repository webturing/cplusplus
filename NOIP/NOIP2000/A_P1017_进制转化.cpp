#include <bits/stdc++.h>
using namespace std;
string D = "0123456789ABCDEFGHIJ";

pair<int, int> div_mod(int n, int r) {
    if (n >= 0) {
        return make_pair(n / r, n % r);
    }
    if (n % r == 0) {
        return make_pair(n / r, 0);
    }

    if (r < 0) {
        return make_pair(n / r + 1, n % r - r);
    }
    return make_pair(-n / r + 1, n % r - r);
}
int main(int argc, char const *argv[]) {
    int n, base;
    cin >> n >> base;
    int n1 = n;
    vector<int> v;
    int r = base;
    while (n) {
        pair<int, int> res = div_mod(n, r);
        v.push_back(res.second);
        n = res.first;
  }
    reverse(v.begin(), v.end());
    cout << n1 << "=";
    for (auto item:v) {
        cout << D[item];
    }
    cout << "(base" << base << ")" << endl;
  return 0;
}