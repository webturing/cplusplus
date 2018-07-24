#include <bits/stdc++.h>

using namespace std;
map<int, set<int>> f;
int n, k;

void merge(int a, int b) {
    set<int> c;
    for (auto i:f[a])c.insert(i);
    for (auto i:f[b])c.insert(i);
    for (int i = 1; i <= n; i++)
        if (find(f[i].begin(), f[i].end(), a) != f[i].end() || find(f[i].begin(), f[i].end(), b) != f[i].end())
            f[i] = c;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        f[i].insert(i);
    while (k--) {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }
    int mx = f[1].size();
    for (int i = 2; i <= n; i++)
        if (f[i].size() > mx)mx = f[i].size();
    int sz = 0;
    set<set<int>> s;
    for (auto e:f)
        s.insert(e.second);
    cout << s.size() << " " << mx << endl;

    return 0;
}