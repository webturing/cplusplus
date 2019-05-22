#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

int main() {
    ifstream cin("input.txt");
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &e:a)cin >> e, e = abs(e);
    sort(a.begin(), a.end());
    LL cnt = 0;
    for (int i = 0; i < n; i++) {
        int &x = a[i];
        if (x > 0) {//2x>=y>=x
            auto left = lower_bound(a.begin() + i + 1, a.end(), x );
            auto right = upper_bound(a.begin() + i + 1, a.end(), 2 * x);
            cnt += right - left;
        } else if (x < 0) {//2*abs(x)>=y>=x/2
            auto left = lower_bound(a.begin() + i + 1, a.end(), x / 2);
            auto right = upper_bound(a.begin() + i + 1, a.end(), 2 * -x);
            cnt += right - left;
        }
    }

    cout << cnt << endl;
    return 0;
}

