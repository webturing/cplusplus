#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <stack>
#include <queue>

typedef long long LL;
using namespace std;

LL n, m, r, v[100005];
int tot, head[100005], size[100005], d[100005], son[100005], top[100005];
int rk[100005], id[100005], cnt, f[100005], num[100005 << 2];
LL tr[100005 << 2];

struct Node {
    int v, next;
} a[100005 << 1];

void read(LL &x) {
    char ch = getchar();
    x = 0;
    for (; ch < '0' || ch > '9'; ch = getchar());
    for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}

void read1(int &x) {
    char ch = getchar();
    x = 0;
    for (; ch < '0' || ch > '9'; ch = getchar());
    for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}


void dfs1(int x) {
    d[x] = d[f[x]] + 1, size[x] = 1;
    for (int v, i = head[x]; i != -1; i = a[i].next) {
        v = a[i].v;
        if (v == f[x]) continue;
        f[v] = x;
        dfs1(v);
        size[x] = size[x] + size[v];
        if (size[v] > size[son[x]]) son[x] = v;
    }
}

void dfs2(int x, int tp) {
    top[x] = tp, id[x] = ++cnt, rk[cnt] = x;
    if (son[x]) dfs2(son[x], tp);
    for (int v, i = head[x]; i != -1; i = a[i].next) {
        v = a[i].v;
        if (v == f[x] || v == son[x]) continue;
        dfs2(v, v);
    }
}

void up(int rt) {
    tr[rt] = tr[rt << 1] + tr[rt << 1 | 1];
    num[rt] = num[rt << 1] + num[rt << 1 | 1];
}

void build(int l, int r, int rt) {
    if (l == r) {
        tr[rt] = v[rk[l]];
        if (tr[rt] == 1LL) num[rt] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, rt << 1), build(mid + 1, r, rt << 1 | 1);
    up(rt);
}

void update(int L, int R, int l, int r, int rt) {
    //printf("%d %d %lld\n", rt, num[rt], tr[rt]);
    if (tr[rt] == num[rt]) return;
    if (L <= l && r <= R && l == r) {
        tr[rt] = sqrt(tr[rt]);
        if (tr[rt] == 1) num[rt] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    if (mid >= L) update(L, R, l, mid, rt << 1);
    if (mid < R) update(L, R, mid + 1, r, rt << 1 | 1);
    up(rt);
}

LL query(int L, int R, int l, int r, int rt) {
    if (l == L && r == R) {
        return tr[rt];
    }
    int mid = (l + r) >> 1;
    LL ans = 0;
    if (R <= mid) ans = query(L, R, l, mid, rt << 1);
    else if (L > mid) ans = query(L, R, mid + 1, r, rt << 1 | 1);
    else ans = query(L, mid, l, mid, rt << 1) + query(mid + 1, R, mid + 1, r, rt << 1 | 1);
    return ans;
}

void updates(int x, int y) {
    while (top[x] != top[y]) {
        if (d[top[x]] < d[top[y]]) swap(x, y);
        update(id[top[x]], id[x], 1, n, 1);
        x = f[top[x]];
    }
    if (id[x] > id[y]) swap(x, y);
    update(id[x], id[y], 1, n, 1);
}

LL sum(int x, int y) {
    LL ans = 0;
    while (top[x] != top[y]) {
        if (d[top[x]] < d[top[y]]) swap(x, y);
        ans = ans + query(id[top[x]], id[x], 1, n, 1);
        x = f[top[x]];
    }
    if (id[x] > id[y]) swap(x, y);
    ans = ans + query(id[x], id[y], 1, n, 1);
    return ans;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    memset(head, -1, sizeof(head));
    read(n), read(m);
    r = 1;
    for (int i = 1; i <= n; i++) read(v[i]);
    for (int u, v, i = 1; i < n; i++) {
        read1(u), read1(v);
        a[tot] = Node{v, head[u]}, head[u] = tot++;
        a[tot] = Node{u, head[v]}, head[v] = tot++;
    }
    cnt = 0, dfs1(r), dfs2(r, r);
    cnt = 1, build(1, n, 1);
    for (int op, x, y, i = 1; i <= m; i++) {
        read1(op), read1(x), read1(y);
        if (op == 0) updates(x, y);
        else if (op == 1) printf("%lld\n", sum(x, y));
    }

    return 0;
}