//
// Created by jal on 18-6-25.
//

#include <bits/stdc++.h>
using namespace std;
stack<int>s;
int dfs(int n){
    int left;
    if (s.size() == 0){
        left = 2;
    }else{
        left = s.top();
    }
    if(left == n)return 1;
    int ret = 0;
    for(int i = left; i <= n; i++){
        if(i == n){
            ret += 1;
        } else
        if(n % i == 0){
            if(n / i >= i){
                s.push(i);
                ret += dfs( n / i);
                s.pop();
            }

        }
    }
    return ret;
}
int main(){
    ifstream cin("input.txt");
    int T;
    cin >> T;
    while(T--){

        int n;
        cin >> n;
        cout << dfs( n ) << endl;
    }
}