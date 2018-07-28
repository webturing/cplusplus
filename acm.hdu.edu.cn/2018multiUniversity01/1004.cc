#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas) {
        int n, m;
        scanf("%d%d", &n, &m);
        std::vector<int> ends(n, -1);
        for (int i = 0; i < n; ++i) ends[i] = i;
        for (int i = 0; i < m; ++i) {
            int l, r;
            scanf("%d%d", &l, &r);
            ends[l - 1] = std::max(ends[l - 1], r - 1);
        }
        std::set<int> unused;
        for (int i = 1; i <= n; ++i) {
            unused.insert(i);
        }
        std::vector<int> ret(n);
        int l = 0, r = -1;
        for (int i = 0; i < n; ++i) {
            if (r >= ends[i]) continue;
            while (l < i) {
                unused.insert(ret[l++]);
            }
            while (r < ends[i]) {
                ret[++r] = *unused.begin();
                unused.erase(ret[r]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i) putchar(' ');
            printf("%d", ret[i]);
        }
        puts("");
    }
    return 0;
}
