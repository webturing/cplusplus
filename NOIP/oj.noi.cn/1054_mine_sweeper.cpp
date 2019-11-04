//
// Created by jal on 18-7-2.
//

#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream cin("input.txt");
    int n,m;
    cin >> n >> m;
    set<pair<int,int>>r;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char x; cin >> x;
            if(x == '*'){
                r.insert(make_pair(i,j));
            }
        }
    }
    for(int i = 0;  i< n; i++){
        for(int j = 0; j < m; j++){
            if(r.find(make_pair(i,j))!=r.end()){
                cout << "*";
                continue;
            }
            int sum = 0;
            set<pair<int,int>>eight;
            eight.insert(make_pair(i-1,j));
            eight.insert(make_pair(i,j-1));
            eight.insert(make_pair(i+1,j));
            eight.insert(make_pair(i,j+1));
            eight.insert(make_pair(i-1,j-1));
            eight.insert(make_pair(i-1,j+1));
            eight.insert(make_pair(i+1,j-1));
            eight.insert(make_pair(i+1,j+1));
            for(auto p:eight){
                if (r.find(p)!=r.end()){
                    sum++;
                }
            }
            cout <<sum;
        }
        cout << endl;
    }

}