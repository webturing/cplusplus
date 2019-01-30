#include <bits/stdc++.h>

using namespace std;

inline int max3(int a, int b, int c) { return max(max(a, b), c); }

const int MAXN = 1010;
int v[MAXN][MAXN];
int dp[MAXN][MAXN];

int main() {
    ifstream cin("1010.txt");
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        memset(v, 0, sizeof(v));
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < N; i++) {
            int xk, yk, vk;
            cin >> xk >> yk >> vk;
            v[xk][yk] = vk;
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                dp[i][j] = max3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + v[i][j]);
            }
        }
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= N; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        cout << dp[N][N] << endl;
    }

    return 0;
}