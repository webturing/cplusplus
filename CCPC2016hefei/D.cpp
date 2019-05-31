#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;
typedef long long LL;
LL a, b, c, d;
LL Min, Max, x, y;

int main() {
    int n;
    while (~scanf("%lld %lld %lld %lld", &a, &b, &c, &d)) {
        scanf("%d", &n);
        Min = 1e17;
        Max = 0;
        for (int i = 0; i < n; i++) {
            scanf("%lld %lld", &x, &y);
            Min = min(Min, a * c * x * x + b * d * y * y + (a * d + b * c) * x * y);
            Max = max(Max, a * c * x * x + b * d * y * y + (a * d + b * c) * x * y);
        }
        printf("%lld\n", LL(fabs(1.0 * (Max - Min) / (a * d - b * c)) + 0.5));
    }
    return 0;
}