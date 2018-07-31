#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<char>> M(n, vector<char>(n, '-'));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> M[i][j];
    vector<vector<char>> T(n, vector<char>(n, '-'));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> T[i][j];
    set<vector<vector<char>>> A;
    queue<vector<vector<char>>> Q;
    Q.push(M);

    return EXIT_SUCCESS;
}