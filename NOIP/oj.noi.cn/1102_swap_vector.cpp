//
// Created by jal on 18-6-28.
//

#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream cin("input.txt");
    int n,m;
    cin >> n>> m;
    vector<vector<int>>v(n,vector<int>(m));
    for(auto &i:v){
        for(auto &j: i){
            cin >> j;
        }
    }
    int q;
    cin >> q;
    while(q--){
        string op;
        int x,y;
        cin >> op >> x >> y;
        x--;y--;
        if(op[0] == 'C'){
            swap(v[x],v[y]);
        }
        else if(op[0] == 'Q'){
            cout << v[x][y] << endl;
        }
    }
}