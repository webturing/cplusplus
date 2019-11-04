//
// Created by jal on 18-6-26.
//

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector<int>v;
    while(n){
        v.push_back(n%k);
        n/=k;
    }
    string s = "0123456789ABCDEF";
    reverse(v.begin(),v.end());
    for(auto i : v){
        cout << s[i];
    }
    cout << endl;
}