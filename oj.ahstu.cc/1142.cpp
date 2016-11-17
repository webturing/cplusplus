#include <iostream>

using namespace std;

typedef long long LL;

LL cnr(int n, int r) {
    if (r * 2 > n)r = n - r;
    LL ret = 1L;
    for (int i = 0; i < r; i++)
        ret *= (n - i);
    for (int i = r; i >= 2; i--)
        ret /= i;
    return ret;
}

int main() {
    for (int n, r; cin >> n >> r; cout << cnr(n, r) << endl);

    return 0;
}