#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

int main() {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a.push_back(t);
    }

    sort(a.begin(), a.end());

    double cnt = 0;

    for (int i = 0; i < n; i++) {
        int x = abs(a[i]);
        auto left = lower_bound(a.begin(), a.end(), x * -2);
        auto right = upper_bound(a.begin(), a.end(), x * 2 );
        cnt += abs(right - left)/2;
        if (a[i] < *right and a[i] >= *left)--cnt;

    }
    cout << cnt  << endl;
    return 0;
}
}