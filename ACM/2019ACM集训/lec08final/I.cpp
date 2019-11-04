#include<bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f3f;

const int MAXN = 1e5 + 10;
int dis[MAXN];
int n, l, r;

int main() {
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        cin >> l >> r;
        dis[l]++;
        dis[r]++;
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(dis[i] + 1, res);
    }
    cout << res << endl;

    return 0;
}