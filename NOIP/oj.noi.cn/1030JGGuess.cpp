#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int f(LL n) {
    if (n == 1) { return 1; }
    if (n & 1) { n = 3 * n + 1; }
    else { n >>= 1; }
    return 1 + f(n);
}

int main(int argc, char const *argv[]) {
    LL x;
    cin >> x;
    cout << f(x) << endl;

    return 0;
}
