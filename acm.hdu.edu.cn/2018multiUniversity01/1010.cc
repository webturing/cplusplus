#include <cstdio>
#include <cstring>
#include <algorithm>

using int64 = long long;

const int N = 1e6 + 10, mod = 1e9 + 7;

char s[N];
int steps[N], a[N];

inline void update(int x, int v) { steps[x] = std::min(steps[x], v); }

void solve(int n, bool rev) {
    for (int i = 0; i < n; ++i) a[i] = s[i] == '1';
    int l = 0, r = n - 1;
    while (l < n && !a[l]) ++l;
    while (r >= 0 && !a[r]) --r;
    if (l == n) {
        memset(steps, 0, sizeof(*steps) * n);
        return;
    }
    // printf("%d %d %d\n", l, r, n);
    int ret = 0;
    for (int i = l + 1; i <= r; ++i) {
        a[i] = !a[i];
        ++ret;
    }
    int sum0, sum1, cnt, last;

    auto calc = [&]() {
        sum0 = sum1 = cnt = 0;
        last = -1;
        for (int i = l; i <= r; ++i)
            if (a[i]) {
                last = i;
                if ((++cnt) & 1) sum0 -= i * 2, sum1 += i * 2;
                else sum0 += i * 2, sum1 -= i * 2;
            }
        if (last != -1) {
            if (cnt & 1) sum0 += last * 2, sum0 += std::abs(r - 1 - last) * 2 + 1;
            else sum1 += last * 2, sum1 += std::abs(r - 1 - last) * 2 + 1;
        }
    };

    // 0 <= p < l
    if (l) a[l] = !a[l];
    calc();
    for (int p = 0; p < l; ++p) {
        if ((l - p - 1) & 1) {
//      printf("xx %d %d\n", l, p);
            if (cnt == 0) update(rev ? n - 1 - p : p, (l - p - 1) / 2 * 2 + std::abs(r - l) * 2 + 1 + ret + l - p);
            else update(rev ? n - 1 - p : p, (l - p - 1) / 2 * 2 - (l - 1) * 2 + sum1 + ret + l - p);
        } else {
            update(rev ? n - 1 - p : p, l - p - 1 + sum0 + ret + l - p);
        }
    }
    if (l) a[l] = !a[l];
    // p = l
    calc();
    update(rev ? n - 1 - l : l, sum0 + ret);
    // l < p <= r
    sum0 = sum1 = cnt = 0, last = -1;
    for (int i = l; i <= r; ++i)
        if (a[i]) {
            last = i;
            if ((++cnt) & 1) sum0 -= i, sum1 += i;
            else sum0 += i, sum1 -= i;
        }
    int t_sum = 0, t_cnt = 0, t_last = -1, swap = 0;
    for (int p = l + 1; p <= r; ++p) {
        a[p - 1] = !a[p - 1];
        if (a[p - 1]) {
            t_last = p - 1;
            if ((++t_cnt) & 1) t_sum -= p - 1;
            else t_sum += p - 1;
        } else {
            if (!swap) sum0 += p - 1, sum1 -= p - 1;
            else sum0 -= p - 1, sum1 += p - 1;
            swap ^= 1;
            --cnt;
        }
        ++ret;
        int now = t_sum, true_last;
        if (t_cnt & 1) now += (swap ? sum0 : sum1);
        else now += (swap ? sum1 : sum0);
        if (p - 1 >= last) true_last = t_last;
        else true_last = last;
        if ((t_cnt + cnt) & 1) {
            now += true_last;
            now = now * 2 + std::abs(r - 1 - true_last) * 2 + 1;
        } else {
            now = now * 2;
        }
        update(rev ? n - 1 - p : p, now + ret);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas) {
        int n;
        scanf("%d", &n);
        scanf("%s", s);
        for (int i = 0; i < n; ++i) steps[i] = mod;
        solve(n, 0);
        std::reverse(s, s + n);
        solve(n, 1);
        int64 ret = 0;
        for (int i = 0; i < n; ++i) {
            ret += int64(i + 1) * steps[i] % mod;
        }
        printf("%lld\n", ret % mod);
    }
    return 0;
}
