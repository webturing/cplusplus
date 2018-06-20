#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, m;
    cin >> n >> m;
    long long p = 1LL;
    if (2 * m > n)m = n - m;
    for (int i = 0; i < m; i++)
        p *= (n - i);
    for (int i = 2; i <= m; i++)
        p /= i;
    cout << p << endl;
    return 0;
}