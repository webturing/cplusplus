//
// Created by ubuntu on 18-7-2.
//

#include <bits/stdc++.h>

using namespace std;
const int maxn = 50 + 1;
typedef unsigned long long LL;
LL Q[maxn][maxn];

void fill() {
    for (int i = 0; i < maxn; i++) {
        Q[i][0] = Q[i][i] = 1;
    }
    for (int i = 2; i < maxn; i++) {
        for (int j = 1; j < i; j++) {
            Q[i][j] = Q[i - 1][j] + Q[i - 1][j - 1];
        }
    }
}

int main() {
    ifstream cin("input.txt");
    int n, m;
    cin >> m >> n;
    fill();
    cout << Q[m - 1][n - 1] << endl;
    return 0;
}