#include<bits/stdc++.h>

using namespace std;

int f(int m, int n) {
    if (m == 0 || n == 1)
        return 1;
    if (n > m)
        return f(m, m);
    else
        return f(m, n - 1) + f(m - n, n);
}


int main(void) {
    int t, m, n;
    for (cin >> t; t-- && cin >> m >> n;)
        cout << f(m, n) << endl;
    return 0;
}