//
// Created by jal on 2019-05-21.
//

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    if(n > m || m % n){
        cout << -1 << endl;
        return 0;
    }
    int p = m / n;
    int cnt = 0;
    while(p%2==0){
        cnt++;
        p/=2;
    }
    while(p%3==0){
        cnt++;
        p/=3;
    }
    if(p==1){
        cout << cnt << endl;
    }else{
        cout << -1 << endl;
    }
}