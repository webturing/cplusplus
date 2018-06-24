#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, m;
    cin >> n >> m;
    set<pair<int, int> > blacks;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            int t;
            cin >> t;
            if (t) { blacks.insert(make_pair(i, j)); }
        }
    int tot = 0;
    while (!blacks.empty()) {
        pair<int, int> cur = *blacks.begin();
        queue<pair<int, int> > Q;
        Q.push(cur);
        blacks.erase(blacks.begin());
        while (!Q.empty()) {
            cur = Q.front();
            Q.pop();
            int x = cur.first, y = cur.second;
            vector<pair<int, int>> adj{make_pair(x - 1, y), make_pair(x + 1, y), make_pair(x, y - 1),
                                       make_pair(x, y + 1)};
            for (auto p:adj) {
                auto find = blacks.find(p);
                if (find != blacks.end()) {
                    Q.push(p);
                    blacks.erase(find);
                }
            }
        }
        ++tot;
    }
    cout << tot << endl;
    return 0;
}
