//
// Created by jal on 2019-05-24.
//

#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    auto p = unique(s.begin(), s.end());
    cout << ((p - s.begin()) % 2 ==0? "CHAT WITH HER!" : "IGNORE HIM!" )<< endl;
}