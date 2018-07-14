//
// Created by jal on 18-7-14.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream cin("input.txt");
    int n;
    cin >> n;
    long long a[n + 1];
    a[1] = 1LL;
    a[2] = 2LL;
    for (int i = 3; i <= n; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }
    cout << a[n] << endl;
}