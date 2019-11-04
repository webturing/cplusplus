#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 105;

int a[maxn], b[maxn], sum[maxn][maxn];

int main() {
    int T, N, M, x;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < N; i++) {
            sum[i][i] = a[i];
            for (int j = i + 1; j < N; j++)
                sum[i][j] = sum[i][j - 1] ^ a[j];
        }
        scanf("%d", &M);
        for (int k = 0; k < M; k++) {
            scanf("%d", &x);
            int ans1 = 0x3f3f3f3f, ans2 = 0;
            for (int i = 0; i < N; i++) {
                for (int j = i; j < N; j++) {
                    if (abs(sum[i][j] - x) < ans1) {
                        ans1 = abs(sum[i][j] - x);
                        ans2 = (j - i + 1);
                    } else if (abs(sum[i][j] - x) == ans1) ans2 = max(ans2, (j - i + 1));
                }
            }
            printf("%d\n", ans2);
        }
        printf("\n");
    }
    return 0;
}