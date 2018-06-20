#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

string fmt(const double exp, int scale = 6) {
    ostringstream os;
    os << setiosflags(ios::fixed) << exp;
    return os.str();
}

#define LOCAL

int main(int argc, char const *argv[]) {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    ifstream cin("input.txt");
    assert(cin);
    LL start = clock();
#endif
    const char MINE = '*';
    const char EMPTY = ' ';
    for (int m, n, k; cin >> n >> m >> k;) {
        vector<vector<char> > M(n, vector<char>(m, EMPTY));
        for (int x, y; k-- && cin >> x >> y; M[x][y] = MINE);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (M[i][j] == MINE)continue;
                int tot = 0;
                for (int x = max(i - 1, 0); x <= min(i + 1, n - 1); ++x)
                    for (int y = max(j - 1, 0); y <= min(j + 1, m - 1); ++y)
                        if (M[x][y] == MINE)
                            ++tot;
                M[i][j] = tot + '0';
            }
        for (int i = 0; i < n; i++) {
            copy(M[i].begin(), M[i].end(), ostream_iterator<char>(cout, ""));
            cout << endl;
        }
        cout << endl;
    }

#ifdef LOCAL
    LL end = clock();
    cout << "Elapsed(s):" << fmt((double) (end - start) / CLOCKS_PER_SEC) << endl;
#endif
    return 0;
}
