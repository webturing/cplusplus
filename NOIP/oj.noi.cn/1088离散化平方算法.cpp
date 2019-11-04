#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &e:v)cin >> e;
    vector<int> w(v.begin(), v.end());
    sort(v.begin(), v.end());
    unique(v.begin(), v.end());
    for (auto e:w)
        cout << find(v.begin(), v.end(), e) - v.begin() + 1 << " ";
    cout << endl;
    return 0;
}