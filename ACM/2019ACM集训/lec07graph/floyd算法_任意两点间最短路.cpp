//
// Created by jal on 18-9-3.
//

#include <bits/stdc++.h>

using namespace std;
int n, m;
const int MAXN = 50, MAX = 99999;
int dis[MAXN][MAXN];

void init() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                dis[i][j] = MAX;
            } else {
                dis[i][j] = 0;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    init();
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dis[u][v] = min(dis[u][v], w);
        dis[v][u] = min(dis[v][u], w);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dis[i][k] + dis[k][j] < dis[i][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }

    //输出1到每一点的距离
    for (int i = 1; i <= n; i++) {
        cout << dis[1][i] << " ";
    }
    cout << endl;
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