#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long LL;
const char MONSTER = '+';
const char ENTRANCE = 'V';
const char HOME = 'J';
const int INF = 0xffff;

vector<vector<char>> F;
vector<vector<int>> D;
vector<pair<int, int>> monsters;
pair<int, int> entrance;
pair<int, int> home;
int n, m;
int nxt[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
set<pair<int, int>> history;

int dfs(pair<int, int> pos) {
    history.insert(pos);
    if (pos == home) {
        return D[pos.first][pos.second];
    }
    int best = D[pos.first][pos.second];
    for (int i = 0; i < 4; i++) {
        int x = pos.first + nxt[i][0];
        int y = pos.second + nxt[i][1];
        if (x < 0 || y < 0 || x >= n || y >= m)continue;
        pair<int, int> nextPos = make_pair(x, y);
        if (history.find(nextPos) != history.end())continue;
        best = max(best, min(D[nextPos.first][nextPos.second], dfs(nextPos)));
    }
    return best;

}

int main() {
    ifstream cin("input.txt");
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> n >> m;
    F.resize(n);
    for (int i = 0; i < n; i++)F[i].resize(m);
    D.resize(n);
    for (int i = 0; i < n; i++) {
        D[i].resize(m);
        fill(D[i].begin(), D[i].end(), INF);
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> F[i][j];
            if (MONSTER == F[i][j])monsters.push_back(make_pair(i, j));
            if (HOME == F[i][j])home = make_pair(i, j);
            if (ENTRANCE == F[i][j])entrance = make_pair(i, j);
        }

    for (auto monster:monsters) {
        int a = monster.first, b = monster.second;
        for (int r = 0; r < n; ++r)
            for (int c = 0; c < m; c++) {
                D[r][c] = min(D[r][c], abs(r - a) + abs(c - b));
            }
    }
    for (int r = 0; r < n; ++r)
        for (int c = 0; c < m; c++) {
            if (c == 0)
                cerr << endl;
            cerr << D[r][c] << " ";

        }
    cout << dfs(entrance) << endl;
    return 0;
}