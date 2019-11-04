#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <stack>
#include <queue>

typedef long long LL;
using namespace std;

const int sum = 259200;

int n, h, m, s, a[86405];

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    scanf("%d", &n);
    scanf("%d %d %d", &h, &m, &s);
    int p = (h % 12) * 60 * 360 + m * 360 + 6 * s;
    for (int i = 1, A, b, c; i <= n; i++) {
        scanf("%d %d %d", &A, &b, &c);
        a[i] = (A % 12) * 60 * 360 + b * 360 + 6 * c;
    }
    sort(a + 1, a + 1 + n);
    int ans = 0x3f3f3f3f;
    if (p <= a[1]) {
        ans = min(ans, a[n] - p);
        ans = min(ans, sum + p - a[1]);
        for (int i = 1; i < n; i++) {
            ans = min(ans, a[i] - p + a[i] + sum - a[i + 1]);
        }
        for (int i = n; i > 1; i--) {
            ans = min(ans, p + sum - a[i] + a[i - 1] + sum - a[i]);
        }
    } else if (p >= a[n]) {
        ans = min(ans, sum - p + a[n]);
        ans = min(ans, p - a[1]);
        for (int i = 1; i <= n; i++) {
            ans = min(ans, a[i] + sum - p + a[i] + sum - a[i + 1]);
        }
        for (int i = n; i >= 1; i--) {
            ans = min(ans, p - a[i] + a[i - 1] + sum - a[i]);
        }
    } else {
        int p1 = upper_bound(a + 1, a + 1 + n, p) - a;
        int p2 = lower_bound(a + 1, a + 1 + n, p) - a - 1;
        if (p1 >= 1 && p1 <= n) ans = min(ans, p + sum - a[p1]);
        if (p2 >= 1 && p2 <= n) ans = min(ans, sum - p + a[p2]);
        ans = min(ans, p - a[1] + a[n] - a[1]);
        ans = min(ans, a[n] - p + a[n] - a[1]);
        for (int i = 2; i <= p2; i++) {
            ans = min(ans, p - a[i] + sum - a[i] + a[i - 1]);
        }
        for (int i = p1; i <= n; i++) {
            ans = min(ans, a[i] - p + a[i] + sum - a[i + 1]);
        }
    }
    printf("%.2lf\n", 1.0 * ans);

    return 0;
}