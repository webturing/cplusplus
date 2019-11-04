#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (auto &e:a)cin >> e;
    sort(a.begin(), a.end());
    int ans = INT_MAX;
    for (int i = 0; i + n - 1 < m; i++) {
        ans = min(a[i + n - 1] - a[i], ans);
    }
    cout << ans << endl;

    return 0;
}
