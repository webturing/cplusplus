#include<bits/stdc++.h>

using namespace std;
const int maxn = 1000000 + 1;
const int MOD = 32767;
vector<int> p(maxn, 0);

void fill() {
    p[1] = 1;
    p[2] = 2;
    for (int i = 3; i < maxn; i++)
        p[i] = (2 * p[i - 1] + p[i - 2]) % MOD;
}

int main(void) {
    int n, k;
    for (fill(), cin >> n; n-- && cin >> k; cout << p[k] << endl);
    return 0;
}