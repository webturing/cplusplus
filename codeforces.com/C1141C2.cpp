#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

int main() {
    int n;
    cin >> n;
    vector<LL> d(n, 0);
    for (int i = 1; i <= n - 1; i++)cin >> d[i];
    vector<LL> a(n + 1, 0);
    LL left = 1, right = n;

    bool flag = false;
    while (left <= right) {
        a[1] = (right + left) / 2;
        LL s = a[1];
        for (int i = 2; i <= n; i++) {
            a[i] = d[i - 1] + a[i - 1];

            s += a[i];
        }
        if (s > 1LL * n * (n + 1) / 2) {
            right = a[1] - 1;

        } else if (s < 1LL * n * (n + 1) / 2) {
            left = a[1] + 1;
        } else {
            flag = true;
            break;
        }
    }

    map<int, bool> v;
    for (int i = 1; i <= n; i++)v[a[i]] = true;
    for (int i = 1; i <= n; i++)
        if (not v[i]) {
            flag = false;
        }
    if (not flag)
        cout << -1 << endl;
    else {
        for (int i = 1; i <= n; i++)cout << a[i] << " ";
        cout << endl;
    }

    return 0;
}
