//
// Created by jal on 18-9-3.
//
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50, MAXM = 10000, MAX = 99999;
int u[MAXM], v[MAXM], w[MAXM], dis[MAXN];
int n, m;

void init() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        dis[i] = MAX;
    }
    dis[1] = 0;
    for (int i = 1; i <= m; i++) {
        cin >> u[i] >> v[i] >> w[i];
    }
}

int main() {
    init();
    for (int k = 1; k < n; k++) {
        for (int i = 1; i <= m; i++) {
            if (dis[v[i]] > dis[u[i]] + w[i]) {
                dis[v[i]] = dis[u[i]] + w[i];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dis[i] << " ";
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

input:
5 5
2 3 2
1 2 -3
1 5 5
4 5 2
3 4 3

 output:

 0 -3 -1 2 4

 */