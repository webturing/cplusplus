//
// Created by jal on 18-10-4.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int sum = 0;
    int a[n + 1][n + 1] = {0};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = INT_MAX;
        }
    }
    for (int i = 1; i <= n; i++)a[i][i] = 0;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u][v] = w;
        a[v][u] = w;
    }

    int dis[n + 1];
    int vis[n + 1] = {0};
    for (int i = 1; i <= n; i++) {
        dis[i] = a[1][i];
    };
    vis[1] = 1;
    for (int i = 1; i <= n - 1; i++) {
        int Min = INT_MAX;
        int u;
        for (int j = 1; j <= n; j++) {
            if (vis[j] == 0 && Min > dis[j]) {
                Min = dis[j];
                u = j;
            }
        }
        vis[u] = 1;
        sum += dis[u];
        for (int j = 1; j <= n; j++) {
            if (vis[j] == 0 && dis[j] > a[u][j]) {
                dis[j] = a[u][j];
            }
        }
    }
    cout << sum << endl;
}


/*
 * input:
6 9
 2 4 11
 3 5 13
 4 6 3
 5 6 4
 2 3 6
 4 5 7
 1 2 1
 3 4 9
 1 3 2

 output:
 19
 * */