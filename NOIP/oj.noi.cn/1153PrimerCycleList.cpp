#include <bits/stdc++.h>

using namespace std;
const int MAXN = 40;
int n;
int A[MAXN];
bool visited[MAXN] = {0};
bool success = false;
bool primer[MAXN];

void fill() {
    fill(primer, primer + MAXN, true);
    primer[0] = primer[1] = false;
    for (int i = 2; i < MAXN; i++)
        if (primer[i])
            for (int j = i * i; j < MAXN; j += i)primer[j] = false;
}

void dfs(int k) {
    if (success)
        return;
    if (k == n) {
        if (primer[A[0] + A[n - 1]]) {
            copy(A, A + n, ostream_iterator<int>(cout, " "));
            cout << endl;
            success = true;
        }
        return;
    }

    for (int i = 2; i <= n; i++) {
        if (!visited[i] && primer[i + A[k - 1]]) {
            visited[i] = true;
            A[k] = i;
            dfs(k + 1);
            visited[i] = false;
        }

    }
}

int main() {
    ifstream cin("input.txt");
    fill();
    cin >> n;
    if (n & 1) {
        cout << -1 << endl;

    } else {
        A[0] = 1;
        visited[1] = true;

        dfs(1);
        if (!success)
            cout << -1 << endl;
    }
    return 0;
}