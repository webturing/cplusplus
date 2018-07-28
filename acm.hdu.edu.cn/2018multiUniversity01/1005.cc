#include <cstdio>
#include <cstring>
#include <cassert>
#include <set>
#include <map>
#include <queue>

using int64 = long long;
using pii = std::pair<int, int>;

const int N = 1e5 + 10;
const int mod = 1e9 + 7;

struct edge_t {
    int from, to;
    int64 dp[2][2], ways[2][2];

    bool operator<(const edge_t &rhs) const {
        return to < rhs.to;
    }
};

std::set<edge_t> edges[N];

void update(int64 &x, int64 &y, int64 u, int64 v) {
    if (u == -1) return;
    if (x < u) x = u, y = v;
    else if (x == u) y = (y + v) % mod;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas) {
        int n, m;
        scanf("%d%d", &n, &m);
        std::map<pii, pii> mp;
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            --u, --v;
            if (u > v) std::swap(u, v);
            if (!mp.count({u, v})) mp[{u, v}] = {w, 0};
            auto it = mp.find({u, v});
            if (it->second.first < w) it->second = {w, 1};
            else if (it->second.first == w) it->second.second++;
        }
        for (int i = 0; i < n; ++i) edges[i].clear();
        for (auto &&e : mp) {
            edge_t edge;
            edge.from = e.first.first;
            edge.to = e.first.second;
            int weight = e.second.first;
            int cnt = e.second.second;
            memset(edge.dp, -1, sizeof(edge.dp));
            memset(edge.ways, -1, sizeof(edge.ways));
            edge.dp[0][0] = 0;
            edge.ways[0][0] = 1;
            edge.dp[1][1] = weight;
            edge.ways[1][1] = cnt;
            edges[edge.from].insert(edge);
            std::swap(edge.from, edge.to);
            edges[edge.from].insert(edge);
        }
        if (n == 2) {
            auto e = mp.begin()->second;
            printf("%d %d\n", e.first, e.second);
            continue;
        }
        std::queue<int> queue;
        for (int i = 0; i < n; ++i) {
            if (edges[i].size() == 2) queue.emplace(i);
        }
        for (int i = 0; i < n - 2; ++i) {
            int u = queue.front();
            queue.pop();
            edge_t a = *edges[u].begin();
            edges[u].erase(edges[u].begin());
            edge_t b = *edges[u].begin();
            edges[u].erase(edges[u].begin());
            edge_t now;
            now.to = u;
            edges[a.to].erase(now);
            edges[b.to].erase(now);
            now.from = a.to, now.to = b.to;
            int64 dp[2][2], ways[2][2];
            memset(dp, -1, sizeof(dp));
            memset(ways, -1, sizeof(ways));
            for (int x = 0; x < 2; ++x)
                for (int y = 0; x + y < 2; ++y) {
                    for (int s = 0; s < 2; ++s)
                        for (int t = 0; t < 2; ++t) {
                            if (a.dp[x][s] == -1 || b.dp[y][t] == -1) continue;
                            update(dp[s][t], ways[s][t], a.dp[x][s] + b.dp[y][t], a.ways[x][s] * b.ways[y][t] % mod);
                        }
                }

            auto it = edges[now.from].find(now);
            bool find = it != edges[now.from].end();
            if (it != edges[now.from].end()) {
                int64 t_dp[2][2], t_ways[2][2];
                memset(t_dp, -1, sizeof(t_dp));
                memset(t_ways, -1, sizeof(t_ways));
                for (int x = 0; x < 2; ++x)
                    for (int y = 0; y < 2; ++y) {
                        for (int s = 0; x + s < 2; ++s)
                            for (int t = 0; t + y < 2; ++t) {
                                if (dp[x][y] == -1 || it->dp[s][t] == -1) continue;
                                update(t_dp[x + s][y + t], t_ways[x + s][y + t], dp[x][y] + it->dp[s][t],
                                       ways[x][y] * it->ways[s][t] % mod);
                            }
                    }
                memcpy(dp, t_dp, sizeof(t_dp));
                memcpy(ways, t_ways, sizeof(t_ways));
                edges[now.from].erase(now);
                std::swap(now.from, now.to);
                edges[now.from].erase(now);
                std::swap(now.from, now.to);
            }
            for (int x = 0; x < 2; ++x)
                for (int y = 0; y < 2; ++y) {
                    now.dp[x][y] = dp[x][y], now.ways[x][y] = ways[x][y];
                }
            edges[now.from].insert(now);
            std::swap(now.from, now.to);
            for (int x = 0; x < 2; ++x)
                for (int y = 0; y < 2; ++y) {
                    now.dp[x][y] = dp[y][x], now.ways[x][y] = ways[y][x];
                }
            edges[now.from].insert(now);
            if (find && edges[now.from].size() == 2) queue.emplace(now.from);
            if (find && edges[now.to].size() == 2) queue.emplace(now.to);
        }
        assert(queue.size() == 2u);
        int64 dp = -1, ways = -1;
        edge_t e = *edges[queue.front()].begin();
        for (int x = 0; x < 2; ++x)
            for (int y = 0; y < 2; ++y) {
                update(dp, ways, e.dp[x][y], e.ways[x][y]);
            }
        printf("%lld %lld\n", dp, ways);
    }
    return 0;
}
