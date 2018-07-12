#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream cin("input.txt");
    int n, k;
    cin >> n >> k;
    vector<int> v(n, 0);
    vector<int> s(n + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] == 0)
            s[i + 1] = s[i] + 1;
        else
            s[i + 1] = s[i];
    }
    if (s[n] <= k) {
        cout << n << endl;
        return 0;
    }
    int mx = 0, i, j;
    for (i = 1; i <= n; i++) {
        j = upper_bound(s.begin(), s.end(), s[i - 1] + k) - s.begin();
        mx = max(j - i, mx);
    }
    cout << mx << endl;


    return 0;
}