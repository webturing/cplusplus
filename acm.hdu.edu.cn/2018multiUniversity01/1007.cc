// let da(n) = A079559(n): 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0
// 0->0, 1->110
// S(n) = (n-1)*sum_{i=0}^{n-2}da(i) - sum_{i=0}^{n-2}da(i)*i + 1
#include <cstdio>
#include <cassert>

using int64 = long long;

const int mod = 1e9 + 7;

struct value_t {
    int64 len, one, sum;

    value_t() = default;

    value_t(int64 x, int64 y, int64 z) : len(x), one(y), sum(z) {}
    // length, number of 1, sum of i * s[i]
} dp[60];

void prepare() {
    dp[0] = {3, 2, 1};
    for (int i = 1; i < 60; ++i) {
        dp[i].len = dp[i - 1].len + dp[i - 1].one * 2;
        assert(dp[i].len == dp[i - 1].len * 2 + 1);
        dp[i].one = dp[i - 1].one * 2;
        dp[i].sum = (dp[i - 1].sum * 2 + (dp[i - 1].len % mod) * (dp[i - 1].one % mod)) % mod;
        //printf("%lld %lld %lld\n", dp[i].len, dp[i].one, dp[i].sum);
    }
}

// sum0: da(i), sum1: da(i) * i
int64 prefix, sum0, sum1;

void update(int64 len, int64 one, int64 sum) {
    sum0 += one;
    sum1 += sum + (one % mod) * (prefix % mod) % mod;
    prefix += len;
    //printf("%lld %lld\n", sum0, sum1);
    sum0 %= mod, sum1 %= mod;
}

void solve(int64 n, int depth, int trailing) {
    if (n == dp[depth].len + trailing) {
        update(n, dp[depth].one, dp[depth].sum);
        return;
    }
    if (depth == 0) {
        if (n == 1) update(1, 1, 0);
        else update(n, 2, 1);
        return;
    }
    if (n <= dp[depth - 1].len) {
        solve(n, depth - 1, 0);
    } else {
        update(dp[depth - 1].len, dp[depth - 1].one, dp[depth - 1].sum);
        solve(n - dp[depth - 1].len, depth - 1, trailing + 1);
    }
}

int main() {
    prepare();
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas) {
        int64 n;
        scanf("%lld", &n);
        for (int i = 0; i < 60; ++i)
            if (dp[i].len >= n) {
                prefix = sum0 = sum1 = 0;
                solve(n, i, 0);
                assert(n == prefix);
                //printf("%lld %lld\n", sum0, sum1);
                printf("%lld\n", ((n - 1) % mod * (sum0 % mod) % mod - sum1 % mod + 1 + mod) % mod);
                break;
            }
        /*
        const int da[] = {1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1};
        int64 sum2 = 0, sum3 = 0;
        for (int i = 0; i < n - 1; ++i) {
          sum2 += da[i] * i;
          sum3 += da[i];
        }
        sum2 -= 1;
        printf("%lld\n", (n - 1) * sum3 - sum2);
        */
    }
    return 0;
}
