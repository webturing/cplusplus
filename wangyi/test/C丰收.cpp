//
// Created by jal on 18-9-8.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n + 1];
    int s[n + 1];
    s[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    int m;
    cin >> m;
    while (m--) {
        int x;
        cin >> x;
        int pos = upper_bound(s, s + n + 1, x) - s;
        if (binary_search(s, s + n + 1, x)) {
            cout << pos - 1 << endl;
        } else {
            cout << pos << endl;
        }

    }
}
/*
 *
 5
2 7 3 4 9
3
1 25 11
 */