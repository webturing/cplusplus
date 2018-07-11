#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &e:v)cin >> e;
    vector<int> w(v.begin(), v.end());
    sort(v.begin(), v.end());
    auto last = unique(v.begin(), v.end());
    for (auto e:w)
        cout << lower_bound(v.begin(), last, e) - v.begin() + 1 << " ";
    cout << endl;
    return 0;
}