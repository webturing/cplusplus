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

int n, m;
int ans[15][15];

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    while (scanf("%d %d", &n, &m) == 2) {
        if (n % 4 || m % 4) printf("no response\n");
        else {
            ans[1][1] = ans[1][2] = ans[1][3] = ans[2][2] = 1;
            ans[2][1] = ans[3][1] = ans[3][2] = ans[4][1] = 2;
            ans[1][4] = ans[2][3] = ans[2][4] = ans[3][4] = 3;
            ans[3][3] = ans[4][2] = ans[4][3] = ans[4][4] = 4;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (ans[i][j]) continue;
                    ans[i][j] = ans[i % 4 ? i % 4 : 4][j % 4 ? j % 4 : 4];
                }
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    printf("%d", ans[i][j]);
                }
                printf("\n");
            }
        }
    }


    return 0;
}