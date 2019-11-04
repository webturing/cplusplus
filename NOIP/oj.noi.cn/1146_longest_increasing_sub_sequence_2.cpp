//
// Created by ubuntu on 18-7-2.
//

#include <bits/stdc++.h>

const int N = 5001;
int a[N];
int dp[N + 1];
using namespace std;

int main() {
    ifstream cin("input.txt");
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> h;
    h.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        if (a[i] >= *h.rbegin()) {
            h.push_back(a[i]);
            continue;
        }
        auto r = upper_bound(h.begin(), h.end(), a[i]);
        *r = a[i];
    }
    cout << h.size() << endl;
}