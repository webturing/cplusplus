//
// Created by jal on 2019-05-23.
//

#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i:v) {
        cin >> i;
    }
    sort(v.begin(), v.end(), greater<int>());
    vector<int> s(n);
    partial_sum(v.begin(), v.end(), s.begin());
    int f = s.back() / 2;
    auto p = upper_bound(s.begin(), s.end(), f);
    cout << p - s.begin() + 1 << endl;
}