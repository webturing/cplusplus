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

int n;
double a[1005];

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    scanf("%d", &n);
    double ans = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &a[i]);
        if (a[i - 1] < 100) ans += a[i];
        else if (a[i - 1] < 150) ans += a[i] * 0.8;
        else if (a[i - 1] < 400) ans += a[i] * 0.4;
        else ans += a[i];
        a[i] += a[i - 1];
    }
    printf("%.2lf\n", ans);

    return 0;
}