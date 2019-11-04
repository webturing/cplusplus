//
// Created by ubuntu on 18-7-2.
//

#include <bits/stdc++.h>

using namespace std;

const int N = 50001;
int a[N];
int sum[N];

int main() {
    ifstream cin("input.txt");
    int n;
    cin >> n;
    int Q;
    cin >> Q;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = x;
        sum[i] = sum[i - 1] + a[i];
    }
    while (Q--) {
        int x;
        cin >> x;
        auto r = upper_bound(sum, sum + n + 1, x) - sum;
        cout << r << endl;
    }
}