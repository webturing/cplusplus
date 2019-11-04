//
// Created by ubuntu on 18-7-2.
//

//
// Created by ubuntu on 18-7-2.
//
#include <bits/stdc++.h>

using namespace std;
const int maxn = 60 + 1;
typedef unsigned long long LL;

LL f(int n, int m) {
    if (n == 0 || m == 1)return 1;
    if (n < m) {
        return f(n, n);
    }
    return f(n, m - 1) + f(n - m, m);
}

int main() {
    ifstream cin("input.txt");
    int n, m;
    cin >> n >> m;
    cout << f(n - m, m) << endl;
    return 0;
}