#include <bits/stdc++.h>

using namespace std;
int n, A[30];

bool solve(int i, int m) {
    if (m == 0) return true;
    if (i >= n) return false;
    return solve(i + 1, m) || solve(i + 1, m - A[i]);
}

int main() {
    int t, M;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        scanf("%d", &M);
        if (solve(0, M))
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
