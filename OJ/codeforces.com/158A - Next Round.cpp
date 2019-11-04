#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &e:a)cin >> e;
    int score = max(a[k - 1], 1);
    cout << upper_bound(a.begin(), a.end(), score,greater<int>()) - a.begin() << endl;
    return 0;
}