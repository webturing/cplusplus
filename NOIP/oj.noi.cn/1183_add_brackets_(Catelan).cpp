//
// Created by ubuntu on 18-7-9.
//
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

LL C(int n) {
    int m = 2 * n;
    LL ret = 1;
    for (int i = 1; i <= n; i++) {
        ret *= m - i + 1;
        ret /= i;
    }
    return ret / (n + 1);
}

int main() {

    ifstream cin("input.txt");
    int n;
    cin >> n;
    cout << C(n) << endl;
    return 0;
}
