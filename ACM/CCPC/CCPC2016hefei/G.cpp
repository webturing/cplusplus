#include<bits/stdc++.h>

#define N 200010
using namespace std;
int n, m, fa[N], A[N], B[N], s[N];
struct node {
    int c[2], rev, fa;
} t[N];

class lct {
    void pushdown(int x) {
        int lc = t[x].c[0], rc = t[x].c[1];
        if (t[x].rev) {
            if (lc)t[lc].rev ^= 1, swap(t[lc].c[0], t[lc].c[1]);
            if (rc)t[rc].rev ^= 1, swap(t[rc].c[0], t[rc].c[1]);
            t[x].rev = 0;
        }
    }

    void rotate(int x, int k) {
        int y = t[x].fa, f = (t[t[y].fa].c[1] == y);
        pushdown(y);
        pushdown(x);
        if (!t[y].fa)fa[x] = fa[y];
        t[x].fa = t[y].fa;
        t[t[y].fa].c[f] = x;
        t[y].fa = x;
        t[y].c[k] = t[x].c[k ^ 1];
        t[t[y].c[k]].fa = y;
        t[x].c[k ^ 1] = y;
    }

    void splay(int x) {
        while (t[x].fa) {
            int y = t[x].fa, f = t[y].c[1] == x;
            if (!t[y].fa)rotate(x, f);
            else {
                if (f == (t[t[y].fa].c[1] == y))rotate(y, f), rotate(x, f);
                else rotate(x, f), rotate(x, f ^ 1);
            }
        }
        pushdown(x);
    }

    int find(int x) {
        access(x);
        splay(x);
        while (t[x].c[0])x = t[x].c[0];
        return x;
    }

    void access(int x) {
        for (int y = 0; x; y = x, x = fa[x]) {
            splay(x);
            t[t[x].c[1]].fa = 0;
            fa[t[x].c[1]] = x;
            t[x].c[1] = y;
            t[y].fa = x;
            fa[y] = 0;
        }
    }

public:
    int qry(int x) {
        int p = find(x);
        if (s[p])return -1;
        return p;
    }

    void cut(int x, int y) {
        int p = find(x);
        if (A[p] == x && B[p] == y) {
            A[p] = B[p] = 0;
            return;
        }
        access(x);
        splay(y);
        if (fa[y] == x)swap(x, y);
        splay(x);
        t[t[x].c[0]].fa = 0;
        fa[t[x].c[0]] = 0;
        t[x].c[0] = fa[x] = 0;
        p = find(y);
        if (A[p] && B[p])
            if (find(A[p]) != find(B[p]))
                link(A[p], B[p]), A[p] = B[p] = 0;
    }

    void link(int x, int y) {
        if (find(x) == find(y)) {
            int p = find(x);
            A[p] = x;
            B[p] = y;
            return;
        }
        access(x);
        splay(x);
        fa[x] = y;
        t[x].rev ^= 1;
        swap(t[x].c[0], t[x].c[1]);
    }
} T;

int main() {
    int tp, x, y;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &s[i]);
        if (s[i])T.link(i, s[i]);
    }
    while (m--) {
        scanf("%d%d", &tp, &x);
        if (tp == 2)printf("%d\n", T.qry(x));
        else {
            scanf("%d", &y);
            if (s[x])T.cut(x, s[x]);
            if (y)T.link(x, y);
            s[x] = y;
        }
    }
    return 0;
}
 