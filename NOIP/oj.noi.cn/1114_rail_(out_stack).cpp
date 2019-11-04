//
// Created by jal on 18-7-14.
//

#include<bits/stdc++.h>

using namespace std;

int main() {
    ifstream cin("input.txt");
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        stack<int> s;
        int cur = 0;
        for (int i = 1; i <= n; i++) {
            s.push(i);
            while (!s.empty() && s.top() == a[cur]) {
                s.pop();
                cur++;
            }
        }
        if (!s.empty()) {
            cout << "Impossible" << endl;
        } else {
            cout << "Possible" << endl;
        }
    }
}