#include <bits/stdc++.h>

using namespace std;
#define LL long long
#define mod 1000000007
typedef struct Res {
    int x, y;

    bool operator<(const Res &b) const {
        if (y > b.y) return 1;
        return 0;
    }
} Res;
Res now, temp;
priority_queue<Res> q, q2;

int main(void) {
    LL ans;
    int T, n, i, val, s1, s2, cnt;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (i = 1; i <= n; i++) {
            s1 = s2 = 0;
            scanf("%d", &val);
            if (q.empty() == 0) s1 = val - q.top().y;
            if (q2.empty() == 0) s2 = val - q2.top().y;
            if (s1 <= 0 && s2 <= 0) {
                now.y = val;
                q.push(now);
            } else if (s2 >= s1) {
                now = q2.top();
                q2.pop();
                temp = now;
                now.y = val;
                q2.push(now);
                q.push(temp);
            } else {
                now = q.top();
                q.pop();
                now.x = now.y;
                now.y = val;
                q2.push(now);
            }
        }
        ans = cnt = 0;
        while (q2.size()) {
            ans += q2.top().y - q2.top().x;
            cnt += 2;
            q2.pop();
        }
        while (q.empty() == 0) q.pop();
        printf("%lld %d\n", ans, cnt);
    }
    return 0;
}