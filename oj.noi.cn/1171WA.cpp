#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

string fmt(const double exp, int scale = 6) {
    ostringstream os;
    os << fixed << setprecision(scale) << exp;
    return os.str();
}

#define LOCAL
string CP = "M+-|1234Z";
pair<int, int> M, Z;
int r, c;
vector<vector<char>> v(26, vector<char>(26, '.'));
bool CC[9][9] = {0, 1, 1, 1, 1, 1, 1, 1, 1,
                 0, 1, 1, 1, 1, 1, 1, 1, 1,
                 0, 1, 1, 0, 1, 1, 1, 1, 1,
                 0, 1, 0, 1, 1, 1, 1, 1, 1,
                 0, 1, 1, 1, 0, 1, 1, 1, 1,
                 0, 1, 1, 1, 1, 0, 1, 1, 1,
                 0, 1, 1, 1, 1, 1, 0, 1, 1,
                 0, 1, 1, 1, 1, 1, 1, 0, 1,
                 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

bool judge(char x, char y) {
    int xx = CP.find(x);
    int yy = CP.find(y);
    return CC[xx][yy];
}

bool judge(pair<int, int> x, pair<int, int> y) {
    return judge(v[x.first][x.second], v[y.first][y.second]);
}

set<pair<int, int>> history;

bool dfs(pair<int, int> p) {
    history.insert(p);
    if (p == Z)return true;
    int nex[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
    for (int i = 0; i < 4; i++) {
        int nx = p.first + nex[i][0];
        int ny = p.second + nex[i][1];
        if (nx < 1 || nx > r || ny < 1 || ny > c)continue;
        if (v[nx][ny] == '.')continue;
        pair<int, int> q = make_pair(nx, ny);
        if (history.find(q) != history.end())continue;
        if (!judge(p, q))
            continue;
        if (dfs(q))
            return true;
    }
    return false;
}


int main(int argc, char const *argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    ifstream cin("input.txt");
    assert(cin);
    LL start = clock();
#endif
    cin >> r >> c;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> v[i][j];
            if (v[i][j] == 'M')M = make_pair(i, j);
            if (v[i][j] == 'Z')Z = make_pair(i, j);
        }
    }

    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++) {
            if (v[i][j] == '.') {
                for (int k = 7; k >= 1; k--) {
                    v[i][j] = CP[k];
                    history.clear();
                    if (dfs(M)) {
                        cout << i << " " << j << endl;
                        cout << CP[k] << endl;
                        return 0;
                    }
                    v[i][j] = '.';

                }
            }
        }

#ifdef LOCAL
    LL end = clock();
    cout << "Elapsed " << fmt((double) (end - start) / CLOCKS_PER_SEC) << endl;
#endif
    return 0;
}
