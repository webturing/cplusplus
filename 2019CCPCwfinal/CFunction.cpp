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

int n, m, num[100005];
int a[100005], b[100005], c[100005];

struct node {
    LL w;
    int id, num;

    bool operator<(const node &rhs) const {
        return w == rhs.w ? a[id] > a[rhs.id] : w > rhs.w;
    }
};

LL fun(LL p, int x) {
    return a[x] * p * p + b[x] * p + c[x];
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    while (scanf("%d %d", &n, &m) == 2) {
        for (int i = 1; i <= n; i++) {
            scanf("%d %d %d", &a[i], &b[i], &c[i]);
        }
        LL ans = 0;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            int t1 = min(max(1, -b[i] / (2 * a[i])), m - n + 1);
            int t2 = t1 + 1;
            if (fun(t1, i) < fun(t2, i)) sum += t1, num[i] = t1;
            else sum += t2, num[i] = t2;
        }
        for (int i = 1; i <= n; i++) ans += fun(num[i], i);
        if (sum < m) {
            priority_queue <node> q;
            for (int i = 1; i <= n; i++) q.push(node{2 * a[i] * num[i] + a[i] + b[i], i, num[i] + 1});
            while (sum < m) {
                node t = q.top();
                q.pop();
                ans += t.w;
                LL temp = 2 * t.num + 1;
                q.push(node{temp * a[t.id] + b[t.id], t.id, t.num + 1});
                sum++;
            }
        } else if (sum > m) {
            priority_queue <node> q;
            for (int i = 1; i <= n; i++) {
                if (num[i] <= 1) continue;
                LL temp = 2 * num[i] - 1;
                q.push(node{-temp * a[i] - b[i], i, num[i] - 1});
            }
            while (sum > m) {
                node t = q.top();
                q.pop();
                ans += t.w;
                if (t.num > 1) {
                    LL temp = 2 * t.num - 1;
                    q.push(node{-temp * a[t.id] - b[t.id], t.id, t.num - 1});
                }
                sum--;
            }
        }
        printf("%lld\n", ans);
    }


    return 0;
}
 