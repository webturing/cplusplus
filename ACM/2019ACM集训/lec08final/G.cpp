#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cmath>

using namespace std;
#define inf 0x3f3f3f3f
const int maxn = 210;
int mmp[maxn][maxn];
int arr[maxn][maxn];
int n, m;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

struct Point {
    int x, y;
};
Point zl[maxn][maxn];

void work() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        int ans = inf;
        memset(mmp, 0, sizeof(mmp));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                zl[i][j].x = zl[i][j].y = 0;
                cin >> mmp[i][j];
                arr[i][j] = arr[i][j - 1] + mmp[i][j];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i > 1) {
                    if (gcd(abs(mmp[i][j]), abs(mmp[i - 1][j])) == 1)
                        zl[i][j].x++;
                }
                if (j > 1) {
                    if (gcd(abs(mmp[i][j]), abs(mmp[i][j - 1])) == 1)
                        zl[i][j].x++;
                }
                if (i < n) {
                    if (gcd(abs(mmp[i][j]), abs(mmp[i + 1][j])) == 1)
                        zl[i][j].y++;
                }
                if (j < m) {
                    if (gcd(abs(mmp[i][j]), abs(mmp[i][j + 1])) == 1)
                        zl[i][j].y++;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                int sum[maxn];
                sum[0] = 0;
                for (int k = 1; k <= n; k++) {
                    sum[k] = sum[k - 1] + arr[k][i] - arr[k][j];
                }
                int mmin = 0;
                vector<int> v;
                for (int k = 1; k <= n; k++) {
                    if (zl[k][j + 1].x == 0) {
                        if (v.size() < 1)
                            v.push_back(k);
                        else {
                            v.push_back(k);
                            if (v.size() == 1) {
                                mmin = sum[v[v.size() - 1] - 1] - sum[v[v.size() - 2] - 1];
                            } else {
                                int temp = sum[v[v.size() - 1] - 1] - sum[v[v.size() - 2] - 1];
                                mmin = min(temp, mmin + temp);
                            }
                        }
                    }
                    if (zl[k][i].y == 0) {
                        if (v.size() > 0) {
                            int temp = sum[k] - sum[v[v.size() - 1] - 1];
                            temp = min(temp, temp + mmin);
                            ans = min(ans, temp);
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
}

int main() {
    work();
    return 0;
}