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

int n, l, K, num[100005];
char s[100005];
int dp[100005][15][28];

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    scanf("%d %d %d", &n, &l, &K);
    scanf("%s", s + 1);
    // if(K >= n) {printf("0\n"); return 0;}
    for (int i = 1; i <= n; i++) {
        num[i] = num[i - 1] + 1;
        if (!i) num[i] = 1;
        int j = i + 1;
        for (; j <= n; j++) {
            if (s[j] == s[i]) num[j] = num[i];
            else break;
        }
        i = --j;
    }
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    dp[1][1][s[1] - 'a'] = 0;
    for (int i = 0; i < 26; i++) if (i != s[1] - 'a') dp[1][1][i] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= min(i, K); j++) {
            int min1 = 0x3f3f3f3f, min2 = 0x3f3f3f3f, tp = max(1, i - l);
            for (int k = 0; k < 26; k++) min2 = min(min2, dp[tp][j - 1][k]);
            for (int k = 0; k < 26; k++) min1 = min(min1, dp[i - 1][j - 1][k]);
            // printf("%d %d %d\n", i, j, min1);
            for (int k = 0; k < 26; k++) {
                if (s[i] - 'a' == k && num[i] - (i - l < 1 ? 0 : num[i - l]) <= 1) {
                    dp[i][j][k] = min1;
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
                    dp[i][j][k] = min(dp[i][j][k], dp[tp][j][k]);
                    dp[i][j][k] = min(dp[i][j][k], min2 + 1);
                } else {
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k] + 1);
                    dp[i][j][k] = min(dp[i][j][k], min(dp[tp][j][k] + 1, min2 + 1));
                }
                // printf("%d %d %d %d\n", i, j, k, dp[i][j][k]);
            }
        }
    }
    int ans = n;
    for (int i = 0; i <= min(K, n); i++) for (int j = 0; j < 26; j++) ans = min(ans, dp[n][i][j]);
    printf("%d\n", ans);

    return 0;
}