#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, m, a;
    cin >> n >> m >> a;
    cout << 1LL * ((n + a - 1) / a) *((m + a - 1) / a) << endl;
    return 0;
}