//
// Created by jal on 2019-07-28.
//

#include <bits/stdc++.h>
using namespace std;
template<typename T = int>
T read(){
    T x;
    cin >> x;
    return x;
}

int main(){
    int n = read();
    vector<int>v(n);
    for(auto& i: v){
        cin >> i;
    }
    map<int, int>M;
    for(auto i: v){
        int x = i;
        while(x != 1){
            if(x % 2 == 0){
                x /= 2;
            }else{
                x = (3*x + 1)/2;
            }
            M[x] = 1;
        }
    }
    sort(v.begin(), v.end(), greater<int>());
    bool f = false;
    for(auto i: v){
        if(!M[i]){
            if(f){
                cout << ' ';
            }else{
                f = true;
            }
            cout << i;
        }
    }
}