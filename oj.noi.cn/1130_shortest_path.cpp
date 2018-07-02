//
// Created by ubuntu on 18-7-2.
//
#include <bits/stdc++.h>

using namespace std;
struct jal {
    int father;
    int v;
    int step;
};

struct three {
    three(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}

    int x, y, z;

    bool operator==(const three that) const {
        return x == that.x && y == that.y && z == that.z;
    }

    bool operator<(const three that) const {
        if (x != that.x) {
            return x < that.x;
        }
        if (y != that.y) {
            return y < that.y;
        }
        return z < that.z;

    }
};

struct Edge {
    int to, next;
};
const int N = 3001, M = 20001 * 2;
int count_edge = 0;
int head[N];
Edge edges[M];

void add_edge(int x, int y) {
    edges[count_edge].to = y;
    edges[count_edge].next = head[x];
    head[x] = count_edge++;
}

int main() {
    three ta(1, 2, 3);
    three tb(1, 2, 3);
    assert(ta == tb);
    ifstream cin("input.txt");
    memset(head, -1, sizeof(head));
    int n, m, k;
    cin >> n >> m >> k;
    vector<three> s;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        add_edge(x, y);
        add_edge(y, x);
    }
    for (int i = 1; i <= k; i++) {
        three t;
        cin >> t.x >> t.y >> t.z;
        s.push_back(t);
    }
    sort(s.begin(), s.end());
    queue<jal> q;
    jal start;
    start.father = 1;
    start.v = 1;
    start.step = 0;
    q.push(start);
    while (!q.empty()) {
        jal first = q.front();
        q.pop();
        if (first.v == n) {
            cout << first.step;
            break;
        }
        for (int i = head[first.v]; i != -1; i = edges[i].next) {
            int v = edges[i].to;
            three temp;
            temp.x = first.father;
            temp.y = first.v;
            temp.z = v;
            bool f = binary_search(s.begin(), s.end(), temp);
            if (f)continue;
            jal node;
            node.father = first.v;
            node.v = v;
            node.step = first.step + 1;
            q.push(node);
        }
    }
}
