#include<bits/stdc++.h>

#define ll long long
using namespace std;
const int N = 1e5 + 5;
map<int, int> mp[N];
int n, m, u, v, a[N], f[N];
vector<int> g[N];
ll sum, ans[N];

void dfs(int u, int fa) {
    f[u] = fa;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v != fa) {
            dfs(v, u);
            if (a[v] == a[u]) sum++;
            sum += mp[u][a[v]];
            mp[u][a[v]]++;
        }
    }
}

void DFS(int u) {
    int rt = f[u];
    if (rt) {
        ll res = sum - mp[rt][a[rt]];
        mp[rt][a[u]]--;///去掉u作为兄弟节点的贡献
        for (auto tp : mp[u])///去掉兄弟节点贡献
            res += 1ll * tp.second * mp[rt][tp.first];
        mp[rt][a[u]]++;///恢复
        ans[rt] = max(ans[rt], res);
    }
    if (g[u].size() < 2 && u != 1) {///根节点特判
        ans[u] = sum - mp[rt][a[u]] + 1;///去掉父子节点的贡献
        if (a[rt] == a[u])///去掉兄弟节点的贡献
            ans[u]--;
    }
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v != f[u]) DFS(v);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    DFS(1);
    for (int i = 1; i < n; i++) printf("%lld ", ans[i]);
    printf("%lld\n", ans[n]);
    return 0;
}