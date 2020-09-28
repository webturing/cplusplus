#include <bits/stdc++.h>

using namespace std;
#define all(a) a.begin(), a.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    using pii = pair<int, int>;
    vector <vector<pii>> G(n);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    vector <vector<int>> dp(n, vector<int>(max(k + 1, n + 1)));
    vector <vector<int>> sum(n, vector<int>(max(k + 1, n + 1)));
    function<void(int, int)> dfs = [&](int cur, int pre) {
        for (auto i : G[cur]) {
            if (i.first != pre) dfs(i.first, cur);
        }
        for (int dep = 0; dep <= n; dep++) {
            for (auto i : G[cur]) {
                if (i.first == pre) continue;
                if (dep == 0)
                    dp[cur][dep] =
                            max(dp[cur][dep],
                                i.second + sum[cur][k] - dp[i.first][k - 1] + dp[i.first][k]);
                else
                    dp[cur][dep] =
                            max(dp[cur][dep], sum[cur][max(dep, k - dep)] -
                                              dp[i.first][max(dep - 1, k - dep - 1)] +
                                              dp[i.first][dep - 1]);
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            dp[cur][i] = max(dp[cur][i], dp[cur][i + 1]);
            if (pre != -1) sum[pre][i + 1] += dp[cur][i];
        }
    };
    dfs(0, -1);
    cout << dp[0][0] << endl;
    return 0;
}
/**
 * 题目名称：韭菜国数据结构习题

题目描述
韭菜国的数据结构课，是和别处不同的：都是教室墙上一块大黑板，老师在讲台上热情洋溢，学生却坐在下面打瞌睡，偶尔有随堂练习便翻一翻辅导书把答案抄上去——这是当年的事，现在的随堂习题都是请别的学校的算法竞赛选手原创的，大部分的学生多是对学习没兴趣的，做不出来，只有平时主动认真学习的，才能在老师把题目布置下来后，不疾不地说出思路，把答案写出来。今天的随堂习题是：有一棵 $n$ 个节点带边权的无根树（回想一下：无根树是一个联通的无向图，且任意两节点之间只有一条路径），你需要选出树上的一些边，保证这些边中任意两条之间都隔着至少 $k$ 条边，你需要求出满足限制的边集的权重之和的最大值。
程序输入说明
第一行两个正整数 $n$ 和 $k$，含义见题面。保证 $n \le 1000, k \le n$。 接下来 $n-1$ 行，每行三个整数 $u, v, w$，表示 $u, v$ 之间存在一条权重为 $w$ 的边，保证 $1\le u,v\le n, 1\le w\le 1000$。
程序输出说明
输出一个整数，表示满足限制的边集权重之和的最大值。
程序输入样例
5 1
5 1 3
3 5 1
2 1 2
4 5 2
程序输出样例
4
*/