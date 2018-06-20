#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

string fmt(const double exp, int scale = 2) {
    ostringstream os;
    os << setiosflags(ios::fixed) << setprecision(scale) << exp;
    return os.str();
}

#define LOCAL

char dfs(const vector<vector<char> > &A) {
    int n = A.size(), m = A[0].size();
    map<pair<int, int>, bool> visited;
    queue<pair<int, int> > Q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                Q.push(make_pair(i, j));
                visited[make_pair(i, j)] = true;
            }
        }
    while (!Q.empty()) {
        pair<int, int> e = Q.front();
        Q.pop();
        visited[e] = true;
        int r = e.first, c = e.second;
        if (A[r][c] == '#')
            continue;
        if (r > 0) {
            pair<int, int> t = make_pair(r - 1, c);
            if (!visited[t]) {
                Q.push(t);
                visited[t] = true;
            }
        }
        if (r < n - 1) {
            pair<int, int> t = make_pair(r + 1, c);
            if (!visited[t]) {
                Q.push(t);
                visited[t] = true;
            }
        }

        if (c > 0) {
            pair<int, int> t = make_pair(r, c - 1);
            if (!visited[t]) {
                Q.push(t);
                visited[t] = true;
            }
        }
        if (c < m - 1) {
            pair<int, int> t = make_pair(r, c + 1);
            if (!visited[t]) {
                Q.push(t);
                visited[t] = true;
            }
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (A[i][j] == '.' && !visited[make_pair(i, j)])
                return 'A';
    return 'H';
}


int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
#ifdef LOCAL
    ifstream cin("input.txt");
    assert(cin);
    LL start = clock();
#endif
    int T, n, m, no = 0;
    for (cin >> T; T-- && cin >> n >> m;) {
        vector<vector<char> > A(n + 2, vector<char>(m + 2, '.'));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> A[i][j];
#ifdef LOCAL
//        for (int i = 0; i <= n + 1; i++) {
//            copy(A[i].begin(), A[i].end(), ostream_iterator<char>(cout, ""));
//            cout << endl;
//        }
#endif
        cout << "Case " << ++no << ":" << dfs(A) << endl;
    }


#ifdef LOCAL
    LL end = clock();
    cout << "Elapsed " << fmt(1.0 * (end - start) / CLOCKS_PER_SEC) <<
         endl;
#endif
    return 0;
}
