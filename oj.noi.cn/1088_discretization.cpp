//
// Created by jal on 18-6-29.
//

#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream cin("input.txt");
    int n;
    cin >> n;
    vector<int>v(n);
    for(auto &i: v){
        cin >> i;
    }
    vector<int>b(v);
    sort(b.begin(), b.end());
    auto e = unique(b.begin(), b.end());
    b.erase(e, b.end());
    for(auto i : v){
        cout << find(b.begin(), b.end(),i) - b.begin() + 1 << " ";
    }
}