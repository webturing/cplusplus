#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 40005;
#define PII pair<int, int>
int degree[maxn];

map<PII, int> M;

int main() {
    /*#ifdef LOCAL_BUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL_BUG*/
    int T, n, m;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        int from, to, val;
        M.clear();
        memset(degree, 0, sizeof(degree));
        for (int i = 1; i < n; i++) {
            scanf("%d%d%d", &from, &to, &val);
            if (val) degree[from]++, degree[to]++;
            M.insert(make_pair(make_pair(min(from, to), max(from, to)), val));
        }
        int op, x, y, z;
        while (m--) {
            scanf("%d", &op);
            if (op == 0) {
                scanf("%d", &x);
                if (degree[x] & 1) printf("Girls win!\n");
                else printf("Boys win!\n");
            } else if (op == 1) {
                scanf("%d%d%d", &x, &y, &z);
                if (z == 1) {
                    if (!M[make_pair(min(x, y), max(x, y))]) {
                        degree[x]++, degree[y]++;
                        M[make_pair(min(x, y), max(x, y))] = 1;
                    }
                } else {
                    if (M[make_pair(min(x, y), max(x, y))]) {
                        degree[x]--, degree[y]--;
                        M[make_pair(min(x, y), max(x, y))] = 0;
                    }
                }
            }
        }
    }
    return 0;
}