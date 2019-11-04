//
// Created by Administrator on 2019/5/16.
//

// Dijkstra算法，链式前向星存图的边

#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100;
const int MAXM = 100 * 100;
struct Edge {
    int val, to, next;
};
int head[MAXN];
Edge edges[MAXM];
int ct = 1;
int dis[MAXN];
int vis[MAXN];
int n, m;

void add(int u, int v, int w) {
    edges[ct].val = w;
    edges[ct].to = v;
    edges[ct].next = head[u];
    head[u] = ct++;
}

const int MAXVALUE = 0xfffff;

int Dijkstra(int source) {
    for (int i = 1; i <= n; i++) {
        dis[i] = MAXVALUE;
    }
    memset(vis, 0, sizeof(vis));
    vis[source] = 1;
    dis[source] = 0;
    for (int i = head[source]; ~i; i = edges[i].next) {
        int v = edges[i].to, w = edges[i].val;
        dis[v] = w;
    }
    for (int t = 1; t < n; t++) {
        int p, min_p = MAXVALUE;
        for (int i = 1; i <= n; i++) {
            if (vis[i] == 0 && dis[i] < min_p) {
                min_p = dis[i];
                p = i;
            }
        }
        vis[p] = 1;
        for (int i = head[p]; ~i; i = edges[i].next) {
            int v = edges[i].to, w = edges[i].val;
            if (dis[p] + w < dis[v]) {
                dis[v] = dis[p] + w;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dis[i] << " ";
    }
    cout << endl;
}

int main() {
    cin >> n >> m;
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    Dijkstra(1);
}

/*
input:
6 9
1 2 1
1 3 12
2 3 9
2 4 3
3 5 5
4 3 4
4 5 13
4 6 15
5 6 4

output:
0 1 8 4 13 17

*/
