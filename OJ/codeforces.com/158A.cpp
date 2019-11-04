//
// Created by jal on 2019-05-23.
//

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector<int>v;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    auto p = upper_bound(v.begin(), v.end(), max(v[k-1], 1), greater<int>());
    cout << p - v.begin() << endl;
    return 0;
}