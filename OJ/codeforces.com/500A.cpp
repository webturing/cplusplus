//
// Created by jal on 2019-05-25.
//

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, t;
    cin >> n >> t;
    t--;
    vector<int>v(n);
    for(int i = 0; i < n-1; i++){
        cin >> v[i];
    }
    int i = 0;
    int flag = 0;
    while(i < n-1){
        if(i == t){
            flag = 1;
            break;
        }
        i += v[i];
    }
    if(i == t){
        flag = 1;
    }
    if(flag == 1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}