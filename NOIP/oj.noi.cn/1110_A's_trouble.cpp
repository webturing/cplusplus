//
// Created by ubuntu on 18-7-7.
//

#include <bits/stdc++.h>

using namespace std;
const int N = 100000 + 1;
const int M = 500000 * 2 + 2;
int head[N];
struct Edge {
    int to, next;
};
Edge edges[M];
int count_edge = 0;

void add(int u, int v) {
    edges[count_edge].to = v;
    edges[count_edge].next = head[u];
    head[u] = count_edge++;
}

int main() {
    ifstream cin("input.txt");
    int n, m;
    cin >> n >> m;
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    stack<int> point;
    for (int i = 1; i <= n; i++) {
        for (int v = head[i]; ~v; v = edges[v].next) {
            point.push(edges[v].to);
        }
        while (!point.empty()) {
            cout << point.top() << " ";
            point.pop();
        }
        cout << endl;
    }
}