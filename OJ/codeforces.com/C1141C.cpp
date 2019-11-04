#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

int main() {
    int n;
    cin >> n;
    vector<LL> d(n, 0);
    vector<LL> a(n + 1, 0);
    for (int i = 1; i < n; i++) cin >> d[i];
    LL s = 1LL * (n) * (n + 1) / 2;

    a[n] = s;
    for (int i = 1; i <= n - 1; i++) a[n] += i * d[i];
    a[n] /= n;

    for (int i = n - 1; i >= 1; i--) a[i] = a[i + 1] - d[i];

    map<int, bool> v;
    for (int i = 1; i <= n; i++)v[a[i]] = true;

    bool flag = true;
    for (int i = 1; i <= n; i++)
        if (not v[i]) {
            flag = false;
            break;
        }
    if (flag) {
        for (int i = 1; i <= n; i++)cout << a[i] << " ";
        cout << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}
