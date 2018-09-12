//
// Created by jal on 18-9-8.
//

#include <bits/stdc++.h>

using namespace std;

struct ZJ {
    int x, y;

    bool operator<(const ZJ that) const {
        return y < that.y;
    }
};

int get_k(int *a, int n) {
    int ret = 0;
    for (int i = 2; i <= n; i++) {
        if (a[i] >= a[1]) {
            ret++;
        }
    }
    return ret;
}

int main() {
    int n, m;
    cin >> n >> m;
    ZJ a[n + 1];
    int c[m + 1];
    for (int i = 1; i <= m; i++) {
        c[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
        c[a[i].x]++;
    }

    long long t = 0;
    while (get_k(c, m) > 0) {
        int temp = 1;
        int minn = 1e9 + 1;
        for (int i = 2; i <= n; i++) {
            if (a[i].x == 1)continue;
            if (a[i].y < minn) {
                minn = a[i].y;
                temp = i;
            }
        }
        c[1]++;
        c[a[temp].x]--;

        t += a[temp].y;
        a[temp].x = 1;
    }
    cout << t << endl;
}
