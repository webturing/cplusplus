#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long LL;
const int MAXN = 51;
LL Q[MAXN][MAXN] = {1};

void fill() {
    for (int i = 0; i < MAXN; i++)Q[i][0] = Q[i][i] = 1;
    for (int i = 2; i < MAXN; i++)
        for (int j = 1; j <= i; j++)
            Q[i][j] = Q[i - 1][j] + Q[i - 1][j - 1];
}

int main() {
    fill();
    int n, m;
    cin >> n >> m;
    cout << Q[n - 1][m - 1] << endl;

    return 0;
}