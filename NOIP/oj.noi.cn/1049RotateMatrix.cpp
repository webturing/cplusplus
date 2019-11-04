#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > A(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> A[i][j];
    vector<vector<int> > B(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            B[i][j] = A[n - 1 - j][i];

    for (int i = 0; i < m; i++) {
        cout << B[i][0];
        for (int j = 1; j < n; j++)
            cout << " " << B[i][j];
        cout << endl;
    }
}