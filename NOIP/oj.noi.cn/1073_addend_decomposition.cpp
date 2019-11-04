//
// Created by jal on 18-6-25.
//

#include <bits/stdc++.h>
using namespace std;
int m,n;
vector<int>v;
int sum = 0;
void dfs(int step){
    if(step >= n){
        sum++;
        return;
    }
    int left = 0;
    if(v.size() > 0){
        left = *v.rbegin();
    }
    if(step == n-1){
        if(left <= m){
            v.push_back(m);
            dfs(step+1);
            v.pop_back();
        }
        return;
    }
    for(int i = left; i <= m; i++){
        if(step < n-1 && m - i >= i){
            v.push_back(i);
            m-=i;
            dfs(step+1);
            v.pop_back();
            m+=i;
        }
    }
}
int main(){
    ifstream cin("input.txt");
    int t;
    cin >> t;
    while(t--){
        v.clear();
        sum = 0;
        cin >> m >> n;
        v.resize(n);
        dfs(0);
        cout << sum << endl;
    }
}