//
// Created by Administrator on 2019/5/16.
//

#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100;
int n, m;
int F[MAXN];

int father(int u) {
    return F[u] == u ? u : F[u] = father(F[u]);
}

void merge(int u, int v) {
    int root_u = father(u);
    int root_v = father(v);
    if (root_u != root_v) {
        F[root_v] = root_u;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        F[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y;
        merge(x, y);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (F[i] == i) {
            cnt++;
        }
    }
    cout << cnt << endl;
}

/*
 input:

 10 9
 1 2
 3 4
 5 2
 4 6
 2 6
 8 7
 9 7
 1 6
 2 4

 output:

 3
 */