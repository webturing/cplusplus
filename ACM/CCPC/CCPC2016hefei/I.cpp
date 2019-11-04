#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
long long bits[80];
long long a1[101], a2[101];

int main() {
    int T;
    int i, j;
    bits[1] = 1;
    for (i = 2; i <= 63; i++) {
        bits[i] = bits[i - 1] << 1;
    }
    scanf("%d", &T);
    while (T > 0) {
        T--;
        long long l, r;
        scanf("%lld%lld", &l, &r);
        long long t = r;
        int p1 = 0;
        while (t != 0) {
            p1++;
            a1[p1] = t % 2;
            t /= 2;
        }
        memset(a2, 0, sizeof(a2));
        t = l;
        int p2 = 0;
        while (t != 0) {
            p2++;
            a2[p2] = t % 2;
            t /= 2;
        }
        long long ans = 0;
        long long d = 0;
//printf("%d %d\n",p1,p2);
        for (i = p1; i >= 1; i--) {
            long long t = d;
            for (j = i; j >= 1; j--)
                t += bits[j];
            if (t <= r)
                ans = max(ans, t | r);
            d += a2[i] * bits[i];
        }
        ans = max(ans, d | r);
        printf("%lld\n", ans);
    }
    return 0;
}