#include <cstdio>
#include <functional>
#include <algorithm>
#include <vector>
#include <queue>

using int64 = long long;

const int mod = 1e9 + 7;

int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas) {
        int n;
        scanf("%d", &n);
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }

        std::vector<int> left(n, -1), right(n, -1), stk(n), parent(n, -1);
        for (int i = 0, top = 0; i < n; ++i) {
            int last = -1;
            while (top && a[i] > a[stk[top - 1]]) {
                last = stk[--top];
            }
            if (top) {
                right[stk[top - 1]] = i;
                parent[i] = stk[top - 1];
            }
            left[i] = last;
            if (last != -1) parent[last] = i;
            stk[top++] = i;
        }

        std::vector<int> inv(n + 2, 1);
        for (int i = 2; i < n + 2; ++i) {
            inv[i] = int64(mod - mod / i) * inv[mod % i] % mod;
        }

        using pii = std::pair<int, int>;
        {
            std::vector<pii> a(n), b(n);
            std::queue<int> queue;
            std::vector<int> cnt(n);
            for (int i = 0; i < n; ++i) {
                a[i] = b[i] = {inv[2], 0};
                if (left[i] == -1 && right[i] == -1) {
                    queue.push(i);
                }
                cnt[i] = (left[i] != -1) + (right[i] != -1);
            }
            while (!queue.empty()) {
                int u = queue.front();
                queue.pop();
                pii res = {(int64) a[u].first * inv[a[u].second] % mod * b[u].first % mod * inv[b[u].second] * 2 % mod,
                           a[u].second + b[u].second + 1};
                int p = parent[u];
                if (p == -1) {
                    printf("%d\n", res.first);
                    break;
                }
                if (cnt[p] == 2) a[p] = res;
                else if (cnt[p] == 1) b[p] = res;
                --cnt[p];
                if (cnt[p] == 0) queue.push(p);
            }
        }
    }
    return 0;
}

