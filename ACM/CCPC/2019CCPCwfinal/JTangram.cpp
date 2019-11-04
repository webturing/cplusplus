#include<bits/stdc++.h>

using namespace std;
using LL = unsigned long long;

int main() {
    LL n;
    cin >> n;
    LL r = 7 + 6 * n + n * (n - 1) / 2;
    cout << r << endl;
    return 0;
}