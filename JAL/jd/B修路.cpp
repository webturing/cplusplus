//
// Created by jal on 18-9-9.
//

#include <bits/stdc++.h>

using namespace std;
const int MAXN = 210;
vector<int> lst[MAXN];
int n;

int dfs(int u, int father) {
    if (lst[u].size() <= 1 && lst[u][0] == father)return 0;
    int ret = 0;
    for (auto v:lst[u]) {
        if (v == father)continue;
        ret += 1;

        ret += dfs(v, u);
    }
    return ret;
}

int main() {
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
        lst[x].push_back(y);
        lst[y].push_back(x);
    }
    int best = 0;
    for (int i = 0; i < n - 1; i++) {
        // 取这条边
        int left = 0;
        int right = 0;
        left = dfs(v[i].first, v[i].second);
        right = dfs(v[i].second, v[i].first);
        best = max(best, left * right);
    }
    cout << best << endl;
}


/*
 * 修路
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
A国有n个城市，他们计划修建n-1条长度为1的道路连接两个城市，城市规划已经给出，最终使得n个城市互相连通，从i城市到j城市有且只有一条唯一路径。

有一家施工队计划承包两段道路的修建工作，要求这两段道路不经过相同的城市(包括路径端点)，他们可以获得的利润是两段道路长度的乘积，现在要使得利润最大化，问最大能获得多少利润。

输入
输入共有n行，第一行包含一个整数n，表示城市的数量。（n<=200）

接下来有n-1行，每行有两个整数,a,b,表示在a城市和b城市之间存在一条长度为1的道路。

输出
输出包含一行，表示最多可以获得的利润是多少


样例输入
4
1 2
2 3
3 4
样例输出
1

Hint
输入样例2
6
1 2
2 3
2 4
5 4
6 4

输出样例2
4

样例解释
样例2应该选取1-2-3和5-4-6,这样一来两条道路的长度都为2，利润最大为2*2=4.
 */