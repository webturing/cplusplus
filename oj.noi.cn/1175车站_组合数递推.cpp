#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long LL;

LL factorial(int n) { return n <= 1 ? 1LL : factorial(n - 1) * n; }

LL binormal(int n, int r) {
    return factorial(n) / factorial(r) / factorial(n - r);
}

LL f(int n, int m) {
    if (m == 0)
        return 1;
    if (n == 1)
        return factorial(m);
    if (m == 1)
        return n;
    LL s = 0;
    for (int k = 0; k <= m; k++)
        s += binormal(m, k) * factorial(k) * f(n - 1, m - k);
    return s;
}


int main() {
    int n, m;
    cin >> n >> m;
    cout << f(n, m) << endl;
    return 0;
}