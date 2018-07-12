//
// Created by jal on 18-7-12.
//

#include<bits/stdc++.h>

using namespace std;

int main() {
    ifstream cin("input.txt");
    int n, k;
    cin >> n >> k;
    int sum = 0;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (k >= n - sum) {
        cout << n << endl;
        return 0;
    }
    int f[n];
    if (a[0] == 0) {
        f[0] = 1;
    } else {
        f[0] = 0;
    }
    for (int i = 1; i < n; i++) {
        if (a[i] == 0) {
            f[i] = f[i - 1] + 1;
        } else {
            f[i] = f[i - 1];
        }
    }
    int m = 0;
    for (int i = 0; i < n; i++) {
        int y = upper_bound(f + i, f + n, f[i] + k) - f;
        m = max(m, y - 1 - i);
    }
    cout << m << endl;
}