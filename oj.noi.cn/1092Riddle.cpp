#include<bits/stdc++.h>

using namespace std;

int main() {
    ifstream cin("input.txt");
    int n, q;
    cin >> n >> q;
    vector<pair<int, string>> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i].first;
    for (int i = 1; i <= n; i++)
        cin >> v[i].second;
    while (q--) {
        string name;
        int l, r;
        cin >> name >> l >> r;
        int tot = 0;
        for (int i = l; i <= r; i++)
            if (v[i].second == name)tot += v[i].first;
        cout << tot << endl;
    }
    return 0;
}