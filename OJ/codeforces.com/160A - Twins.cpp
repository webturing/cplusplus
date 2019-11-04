#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &e:a)cin >> e;
    sort(a.begin(), a.end(), greater<int>());
    partial_sum(a.begin(), a.end(), a.begin());
    auto pos = lower_bound(a.begin(), a.end(), a.back() / 2 + 1);
    cout << pos - a.begin() + 1 << endl;
    return 0;
}