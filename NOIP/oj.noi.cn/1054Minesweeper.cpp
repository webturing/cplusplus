#include <bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[]) {
    int n, m;
    cin >> n >> m;
    vector<vector<char> > M(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> M[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (M[i][j] == '*')
                continue;
            int s = 0;
            int startX = i - 1 >= 0 ? i - 1 : 0;
            int endX = i + 1 > n - 1 ? n - 1 : i + 1;
            int startY = j - 1 >= 0 ? j - 1 : 0;
            int endY = j + 1 > m - 1 ? m - 1 : j + 1;
            for (int x = startX; x <= endX; x++)
                for (int y = startY; y <= endY; y++) {
                    if (M[x][y] == '*')
                        s++;
                }
            M[i][j] = '0' + s;

        }
    for (int i = 0; i < n; i++) {
        copy(M[i].begin(), M[i].end(), ostream_iterator<char>(cout, ""));
        cout << endl;
    }
    return 0;
}