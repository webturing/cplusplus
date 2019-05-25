//
// Created by jal on 2019-05-21.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
//    ifstream cin("input.txt");
    int n;
    cin >> n;
    vector<int>d(n-1);
    for(int i = 0; i < n-1; i++){
        cin >> d[i];
    }
    vector<int>a(n);
    LL s = 1LL*n * (n+1)/2;
    for(int i = 1; i < n; i++){
        s -= 1LL * i * d[n-i-1];
    }
    map<int, int>mp;
    a[0] = s / n;
    mp[a[0]] = 1;
    LL sum = a[0];
    for(int i = 1; i < n; i++){
        a[i] = a[i-1] + d[i-1];
        mp[a[i]]++;
        sum += a[i];
    }
    int flag = 1;
    for(int i = 1; i <= n; i++){
        if(mp[i] != 1){
            flag = 0;
            break;
        }
    }
    if(flag){
        for(auto i : a){
            cout << i << " ";
        }
        cout <<endl;
    }else{
        cout << -1 << endl;
    }
}