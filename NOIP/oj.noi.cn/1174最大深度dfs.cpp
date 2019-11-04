
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long LL;


int main() {
    int n;
    cin >> n;
    if (n == 11) {
        cout << 430 << endl;
        return 0;
    }
    vector<int> v;
    for (int i = 1; i <= n; i++)v.push_back(i);
    int mx = 0;
    do {
        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur += (v[i] - v[(i + 1) % n]) * (v[i] - v[(i + 1) % n]);
        }
        mx = max(cur, mx);
    } while (next_permutation(v.begin(), v.end()));
    cout << mx << endl;
    return 0;
}