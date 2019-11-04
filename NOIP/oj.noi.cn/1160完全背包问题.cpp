#include <bits/stdc++.h>

using namespace std;
const int MAXN = 101;
const int SIZE = 50001;
int dp[SIZE];
int volume[SIZE], value[SIZE], c[MAXN];
int n, v;

void Completepack(int val, int vol) {
    for (int j = vol; j <= v; j++) {
        dp[j] = max(dp[j], dp[j - vol] + val);
    }
}

int main() {
    ifstream cin("input.txt");
    cin >> v >> n;
    for (int i = 1; i <= n; i++)
        cin >> volume[i] >> value[i];
    for (int i = 1; i <= n; i++)
        Completepack(value[i], volume[i]);
    cout << dp[v] << endl;

    return 0;
}