#include <cstdio>
#include <vector>

using int64 = long long;

const int mod = 1e9 + 7;
const int i2 = 500000004, i6 = 166666668;

int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas) {
        int n;
        int64 a, b;
        scanf("%d%lld%lld", &n, &a, &b);
        std::vector<int64> s(n), m(n);
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &s[i]);
            m[i] = s[i] % n;
        }
        std::vector<int> next(n, -1), next_delta(n);
        std::vector<int> prev(n, -1), prev_delta(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                if (i != j && m[i] == m[j]) {
                    int pos = j + s[i] - s[j];
                    if (pos > i && (next[i] == -1 || next_delta[i] > pos - i)) {
                        next[i] = j;
                        next_delta[i] = pos - i;
                    }
                }
        }
        for (int i = 0; i < n; ++i)
            if (next[i] != -1) {
                prev[next[i]] = i;
                prev_delta[next[i]] = next_delta[i];
            }

        auto ceil = [](int64 x, int64 y) -> int64 {
            if (x <= 0) return int64(0);
            else return (x + y - 1) / y;
        };

        auto floor = [](int64 x, int64 y) -> int64 {
            if (x < 0) return -1;
            else return x / y;
        };

        auto psum1 = [&](int64 n) -> int64 {
            if (n < 0) return 0;
            n %= mod;
            return n * (n + 1) % mod * i2 % mod;
        };

        auto psum2 = [&](int64 n) -> int64 {
            if (n < 0) return 0;
            n %= mod;
            return n * (n + 1) % mod * (n * 2 + 1) % mod * i6 % mod;
        };

        auto psum3 = [&](int64 n) -> int64 {
            if (n < 0) return 0;
            n = psum1(n);
            return n * n % mod;
        };

        auto sum1 = [&](int64 x, int64 l, int64 r) {
            // x + kn
            x %= mod;
            return ((r - l + 1) % mod * x % mod +
                    (psum1(r) - psum1(l - 1) + mod) * n % mod) % mod;
        };

        auto sum2 = [&](int64 x, int64 y, int64 l, int64 r) {
            // xy + (x + y)n * k + n^2 * k^2
            x %= mod;
            if (x < 0) x += mod;
            y %= mod;
            if (y < 0) y += mod;
            return ((r - l + 1 + mod) % mod * x % mod * y % mod +
                    (psum1(r) - psum1(l - 1) + mod) * (x + y) % mod * n % mod +
                    (psum2(r) - psum2(l - 1) + mod) * n * n % mod) % mod;
        };

        auto sum3 = [&](int64 x, int64 y, int64 z, int64 l, int64 r) {
            // (xy + (x + y)n * k + n^2 * k^2) * (z + kn)
            // xyz + z(x+y)n * k + zn^2 * k^2 + xyn * k + (x+y)n^2 * k^2 + n^3 * k^3
            x %= mod;
            if (x < 0) x += mod;
            y %= mod;
            if (y < 0) y += mod;
            z %= mod;
            if (z < 0) z += mod;
            return ((r - l + 1) % mod * x % mod * y % mod * z % mod +
                    (psum1(r) - psum1(l - 1) + mod) * (x * y % mod + z * (x + y) % mod) % mod * n % mod +
                    (psum2(r) - psum2(l - 1) + mod) * n * n % mod * (x + y + z) % mod +
                    (psum3(r) - psum3(l - 1) + mod) * n * n % mod * n % mod) % mod;
        };

        int64 ret = 0, inf = b - a + 10;
        for (int i = 0; i < n; ++i) {
            int64 add = 0;
            for (int j = i, cnt = 1; j != -1; j = next[j], ++cnt) {
                int64 ext_i = prev[i] == -1 ? inf : prev_delta[i];
                int64 ext_j = next[j] == -1 ? inf : next_delta[j];
                int64 x = i, y = i + add, l, r;
                int64 mul = cnt * cnt;
                // a <= x + kn; y + kn <= b
                // 1. x + kn - ext_i + 1 >= a && y + kn + ext_j - 1 <= b: ext_i * ext_j * (sum_{k=l}^{r} s[i] + kn)
                l = ceil(a - x + ext_i - 1, n);
                r = floor(b - y - ext_j + 1, n);
                if (l <= r) {
                    //printf("1. %d %d %lld %lld: %lld\n", i, cnt, l, r, ext_i * ext_j % mod * sum1(s[i], l, r) % mod);
                    ret += ext_i * ext_j % mod * sum1(s[i], l, r) % mod * mul % mod;
                }
                // 2. x + kn - ext_i + 2 <= a && y + kn + ext_j - 1 <= b: ext_j * (sum_{k=l}^{r} (s[i] + kn) * (x + kn - a + 1))
                l = ceil(a - x, n);
                r = std::min(floor(a - x + ext_i - 2, n), floor(b - y - ext_j + 1, n));
                if (l <= r) {
                    //printf("2. %d %d %lld %lld: %lld\n", i, cnt, l, r, ext_j * sum2(s[i], x - a + 1, l, r) % mod);
                    ret += ext_j * sum2(s[i], x - a + 1, l, r) % mod * mul % mod;
                }
                // 3. x + kn - ext_i + 1 >= a && y + kn + ext_j - 2 >= b: ext_i * (sum_{k=l}^{r} (s[i] + kn) * (b - y - kn + 1))
                l = std::max(ceil(a - x + ext_i - 1, n), ceil(b - y - ext_j + 2, n));
                r = floor(b - y, n);
                if (l <= r) {
                    //printf("3. %d %d %lld %lld: %lld\n", i, cnt, l, r, (mod - ext_i * sum2(s[i], y - b - 1, l, r) % mod) % mod);
                    ret -= ext_i * sum2(s[i], y - b - 1, l, r) % mod * mul % mod;
                }
                // 4. x + kn - ext_i + 2 <= a && y + kn + ext_j - 2 >= b: sum_{k=l}^{r} (s[i] + kn) * (b - y - kn + 1) * (x + kn - a + 1)
                l = std::max(ceil(a - x, n), ceil(b - y - ext_j + 2, n));
                r = std::min(floor(a - x + ext_i - 2, n), floor(b - y, n));
                if (l <= r) {
                    //printf("4. %d %d %lld %lld: %lld\n", i, cnt, l, r, (mod - sum3(s[i], y - b - 1, x - a + 1, l, r)) % mod);
                    //printf("%lld %lld\n", x - a + 1, b - y + 1);
                    ret -= sum3(s[i], y - b - 1, x - a + 1, l, r) * mul % mod;
                }
                add += next_delta[j];
                ret %= mod;
            }
        }
        ret %= mod;
        ret += mod;
        ret %= mod;
        printf("%lld\n", ret);
    }
    return 0;
}
