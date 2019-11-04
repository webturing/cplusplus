//
// Created by jal on 2019-05-21.
//

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>v(2*n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        v[n+i] = v[i];
    }
    int cnt = 0;
    int res = 0;
    for(int i = 1; i < 2 * n; i++){
        if(v[i] == 0){
            cnt = 0;
        }else{
            if(v[i] == v[i-1]){
                cnt++;
            }else{
                cnt=1;
            }
        }
        res = max(res, cnt);
    }
    cout << res << endl;
}