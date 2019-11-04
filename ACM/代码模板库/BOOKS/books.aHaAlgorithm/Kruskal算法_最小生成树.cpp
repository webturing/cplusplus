//
// Created by jal on 18-10-4.
//

#include<bits/stdc++.h>

using namespace std;

struct Edge {
    int u, v, w;

    bool operator<(const Edge &that) const {
        return w < that.w;
    }
};

int F[100];

int Find(int x) {
    return x == F[x] ? x : Find(F[x]);
}

bool Merge(int x, int y) {
    int rx = Find(x);
    int ry = Find(y);
    if (rx == ry)return false;
    F[ry] = rx;
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)F[i] = i;
    Edge edges[m];
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    sort(edges, edges + m);

    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        if (Merge(edges[i].u, edges[i].v)) {
            cnt++;
            sum += edges[i].w;
            if (cnt >= n - 1)break;
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