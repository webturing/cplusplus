#include <bits/stdc++.h>

using namespace std;
const int MAXN = 10000;

int F[MAXN];

inline int Root(int u) {
    return F[u] == u ? u : F[u] = Root(F[u]);
}

inline void Merge(int u, int v) {
    int root_u = Root(u);
    int root_v = Root(v);
    if (root_u != root_v) {
        F[root_u] = root_v;
    }
}

int main() {
    ifstream cin("input.txt");
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        F[i] = i;
    }
    for (int i = 1; i <= q; i++) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 0)
            Merge(x, y);
        else
            cout << (Root(x) == Root(y)) << endl;
    }
    return 0;
}
