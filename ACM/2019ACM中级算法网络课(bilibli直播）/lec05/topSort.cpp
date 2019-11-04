//
// Created by Administrator on 2019/5/16.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> v[n + 1];
        vector<int> degree(n + 1, 0);
        for (int i = 1; i <= m; i++) {
            int x, y;
            cin >> x >> y;
            v[x].push_back(y);
            degree[y]++;
        }
        priority_queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (degree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> result;
        while (q.size() > 0) {
            int head = q.top();
            q.pop();
            result.push_back(head);
            for (int i = 0; i < v[head].size(); i++) {
                int u = v[head][i];
                if (--degree[u] == 0) {
                    q.push(u);
                }
            }
        }
        if (result.size() == n) {
            for (auto i : result) {
                cout << i << " ";
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
}