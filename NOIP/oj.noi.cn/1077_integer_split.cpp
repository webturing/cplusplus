//
// Created by jal on 18-6-26.
//

#include <bits/stdc++.h>
using namespace std;
vector<int>v;
void dfs(int n){
    if(n == 0){
        if (v.size() <=1)
            return;
        cout<<*v.begin();
        for(int i = 1; i < v.size(); i++){
            cout << "+"<<v[i];
        }
        cout << endl;
        return;
    }
    int left = 1;
    if(v.size()>0){
        left = v.back();
    }
    for(int i = left; i<=n;i++){
        {
            v.push_back(i);
            dfs( n - i);
            v.pop_back();
        }
    }
}
int main(){
    ifstream cin("input.txt");
    int n;
    cin >> n;
    dfs(n);
}