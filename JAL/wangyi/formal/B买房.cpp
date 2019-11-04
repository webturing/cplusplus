//
// Created by jal on 18-9-8.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (n <= 2) {
            cout << "0 0" << endl;
            continue;
        }

        if (k == n) {
            cout << "0 0" << endl;
            continue;
        }

        if (k == n - 1) {
            cout << "0 1" << endl;
            continue;
        }

        cout << "0 " << min(k - 1, n - k) << endl;
    }
}