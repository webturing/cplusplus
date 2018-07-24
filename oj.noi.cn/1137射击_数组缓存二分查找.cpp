#include<bits/stdc++.h>

using namespace std;
const int maxn = 1000;
vector<int> v(maxn + maxn * maxn, 0);

int main(int argc, char const *argv[]) {
    int n, m;
    cin >> n >> m;
    int i;
    for (i = 0; i < n; i++)cin >> v[i];
    for (int x = 0; x < n; x++)
        for (int y = 0; y < n; y++) {
            if (v[x] + v[y] <= m)
                v[i++] = v[x] + v[y];
        }
    v.resize(i);
    sort(v.begin(), v.end());
    int mx = *v.rbegin();// fixed bugs
    for (auto e:v) {
        auto pos = lower_bound(v.begin(), v.end(), m - e);
        int cur = e + *(pos - 1);
        if (cur > mx)mx = cur;
    }
    cout << mx << endl;
    return 0;
}