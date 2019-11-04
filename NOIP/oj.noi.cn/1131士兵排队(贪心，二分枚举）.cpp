#include<bits/stdc++.h>

using namespace std;

const int maxn = 100001;
const int INF = 0x7f7f7f7f;
int a[maxn], b[maxn];

int n;

int check(int t) {
    int l = -INF;
    for (int i = 1; i <= n; i++) {
        int xl = b[i] - t, xr = b[i] + t;
        if (l < xl) l = xl;
        if (l + a[i] - 1 > xr) return 0;
        l += a[i];
    }
    return 1;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    int l = -1, r = INF;
    while (l < r) {
        int m = (l + r) >> 1;
        int xx = check(m);
        if (xx == 1) r = m;
        else l = m + 1;
    }
    cout << r << endl;
    return 0;
}