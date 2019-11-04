#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int m, n, k;
    cin >> m >> n >> k;
    vector<vector<int> > A(m, vector<int>(n));
    vector<vector<int> > B(n, vector<int>(k));
    vector<vector<int> > C(m, vector<int>(k));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++) {
            cin >> B[i][j];
        }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < k; j++) {
            int s = 0;
            for (int l = 0; l < n; l++)
                s += A[i][l] * B[l][j];
            C[i][j] = s;
        }
    for (int i = 0; i < m; i++) {
        copy(C[i].begin(), C[i].end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }

}